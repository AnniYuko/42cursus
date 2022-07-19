/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:28:26 by akroll            #+#    #+#             */
/*   Updated: 2022/07/19 12:07:40 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile int	serv_received;

void	send_str_as_signals(pid_t server_pid, char character)
{
	int	position;

	position = 7;
	while (position >= 0)
	{
		if ((character >> position) & 1)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		position--;
		while (!serv_received)
			;
		serv_received = 0;
	}
}

void	server_feedback(int signum)
{
	if (signum == SIGUSR1)
		serv_received = 1;
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	struct sigaction	sigact_c;
	size_t				i;

	if (argc != 3)
		return (ft_printf("Error: arguments\n./client <PID> \"message\"\n"));
	server_pid = ft_atoi(argv[1]);
	// check if PID is valid
	if (kill(server_pid, 0) != 0 || server_pid <= 0)
		return (ft_printf("PID error\n"));
	sigact_c.sa_handler = server_feedback;
	if (sigaction_init(&sigact_c) != 0)
		return (1);
	i = 0;
	while (argv[2][i] != '\0')
		send_str_as_signals(server_pid, argv[2][i++]);
	send_str_as_signals(server_pid, '\0');
	ft_printf("Server received %d characters\n", i);
	return (0);
}
