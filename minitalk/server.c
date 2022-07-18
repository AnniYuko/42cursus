/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:28:34 by akroll            #+#    #+#             */
/*   Updated: 2022/07/18 15:04:25 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	sigaction_init(struct sigaction *sigact)
{
	sigemptyset(&sigact->sa_mask);
	sigaddset(&sigact->sa_mask, SIGUSR1);
	sigaddset(&sigact->sa_mask, SIGUSR2);
	sigact->sa_sigaction = &signal_handler;
	sigact->sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, sigact, NULL) == -1
		|| sigaction(SIGUSR2, sigact, NULL) == -1)
	{
		write(1, "signal error\n", 14);
		return (1);
	}
	return (0);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
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
				exit(EXIT_FAILURE);
			write(1, "\n", 1);
		}
		else
		{
			write(1, &character, 1);
			if (kill(info->si_pid, SIGUSR1) != 0)
				exit(EXIT_FAILURE);
		}
		position = 0;
		character = 0;
	}
}

int	main(void)
{
	pid_t				my_pid;
	struct sigaction	sigact;

	if (sigaction_init(&sigact) != 0)
		return (1);
	my_pid = getpid();
	ft_printf("pid: %d\n", my_pid);
	while (1)
		pause();
	return (0);
}
