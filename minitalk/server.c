/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:28:34 by akroll            #+#    #+#             */
/*   Updated: 2022/07/04 13:33:36 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_catcher(int signum, siginfo_t *info, void *context)
{
	static unsigned int		position;
	unsigned int			bit;
	static unsigned char	character;

	character <<= 1;
	bit = 0;
	if (signum == SIGUSR1)
	{
		bit = 1;
		character += bit;
	}
	if (++position == 8)
	{
		write(1, &character, 1);
		position = 0;
		character = 0;
	}
}

int main()
{
	pid_t my_pid;
	struct sigaction sigact;

	my_pid = getpid();
	printf("pid: %d\n", my_pid);
	sigemptyset(&sigact.sa_mask);
	sigact.sa_sigaction = signal_catcher;
	sigact.sa_flags = SA_SIGINFO | SA_RESTART;

	if (sigaction(SIGUSR1, &sigact, NULL) == -1)
		perror("USR1 signal");
	if (sigaction(SIGUSR2, &sigact, NULL) == -1)
		perror("USR2 signal");

	while (1)
		pause();
	return 0;
}
