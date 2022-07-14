/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:28:26 by akroll            #+#    #+#             */
/*   Updated: 2022/07/14 13:27:35 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_received;

void	send_str_as_signals(pid_t server_pid, char *str)
{
	int	i;
	int	position;

	i = 0;
	while (str[i] != '\0')
	{
		position = 7;
		while (position >= 0)
		{
			if ((str[i] >> position) & 1)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			position--;
			usleep(50);
		}
		i++;
	}
	i = 8;
	while (i-- > 0)
	{
		kill(server_pid, SIGUSR2);
		usleep(50);
	}
}

void	server_feedback(int signum)
{
	static int	count;

	if (signum == SIGUSR1)
		count++;
	else
	{
		ft_printf("Server received %d characters\n", count);
		g_received = 1;
		count = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	struct sigaction	sigact_c;

	if (argc != 3)
	{
		write(1, "Please enter 3 arguments:\n./client <pid> \"string\"\n", 51);
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	if (kill(server_pid, 0) != 0 || server_pid <= 0)
	{
		write(1, "Error: pid invalid\n", 20);
		return (1);
	}
	sigact_c.sa_handler = server_feedback;
	if (sigaction(SIGUSR1, &sigact_c, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, &sigact_c, NULL) == -1)
		return (1);
	send_str_as_signals(server_pid, argv[2]);
	while (!g_received)
		pause();
	return (0);
}
