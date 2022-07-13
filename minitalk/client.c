/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:28:26 by akroll            #+#    #+#             */
/*   Updated: 2022/07/13 17:49:33 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_str_as_signals(pid_t pid, char *str)
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
			{
				if (kill(pid, SIGUSR1) != 0)
					perror("Error: sending SIGUSR1");
			}
			else
			{
				if (kill(pid, SIGUSR2) != 0)
					perror("Error: sending SIGUSR2");
			}
			usleep(10);
			position--;
		}
		i++;
	}
	i = 8;
	while (i > 0)
	{
		kill(pid, SIGUSR2);
		usleep(10);
		i--;
	}
}

void	message_success_info(int signum)
{
	static int	count;

	if (signum == SIGUSR1)
		count++;
	else
	{
		ft_printf("successfully sent %d to server\n", count);
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
	sigact_c.sa_handler = message_success_info;
	if (sigaction(SIGUSR1, &sigact_c, NULL) == -1)
		perror("USR1 signal");
	if (sigaction(SIGUSR2, &sigact_c, NULL) == -1)
		perror("USR2 signal");
	send_str_as_signals(server_pid, argv[2]);
	while (1)
		pause();
}
