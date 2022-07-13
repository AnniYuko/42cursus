/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:28:34 by akroll            #+#    #+#             */
/*   Updated: 2022/07/13 19:13:06 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void	error_handling(int status)
// {
// 	if (status != 0)
// 	{
// 		perror()
// 		exit
// 	}
// }

void	signal_catcher(int signum, siginfo_t *info, void *context)
{
	static unsigned int		position;
	static char				character;

	(void)context;
	character <<= 1;
	if (signum == SIGUSR1)
		character += 1;
	if (++position == 8)
	{
		if (!character)
		{
			if (kill(info->si_pid, SIGUSR2) != 0)
				perror("Error: sending SIGUSR2");
			write(1, "\n", 1);
		}
		else
		{
			write(1, &character, 1);
			if (kill(info->si_pid, SIGUSR1) != 0)
				perror("Error: sending SIGUSR1");
		}
		position = 0;
		character = 0;
	}
}

int	main(void)
{
	pid_t				my_pid;
	struct sigaction	sigact;

	my_pid = getpid();
	ft_printf("pid: %d\n", my_pid);
	sigemptyset(&sigact.sa_mask);
	sigaddset(&sigact.sa_mask, SIGUSR1);
	sigaddset(&sigact.sa_mask, SIGUSR2);
	sigact.sa_sigaction = signal_catcher;
	sigact.sa_flags = SA_SIGINFO | SA_RESTART;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1)
		perror("USR1 signal");
	if (sigaction(SIGUSR2, &sigact, NULL) == -1)
		perror("USR2 signal");
	while (1)
		pause();
	return (0);
}
