/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:28:26 by akroll            #+#    #+#             */
/*   Updated: 2022/07/13 19:08:15 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_end_of_message(pid_t pid)
{
	int	i;

	i = 8;
	while (i > 0)
	{
		kill(pid, SIGUSR2);
		usleep(50);
		i--;
	}
}

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
			position--;
			usleep(50);
		}
		i++;
	}
	send_end_of_message(pid);
}

void	server_feedback(int signum)
{
	static int	count;

	if (signum == SIGUSR1)
		count++;
	else
	{
		ft_printf("Server received %d characters\n", count);
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
	sigact_c.sa_handler = server_feedback;
	if (sigaction(SIGUSR1, &sigact_c, NULL) == -1)
		perror("USR1 signal");
	if (sigaction(SIGUSR2, &sigact_c, NULL) == -1)
		perror("USR2 signal");
	send_str_as_signals(server_pid, argv[2]);
	while (1)
		pause();
	return (0);
}
