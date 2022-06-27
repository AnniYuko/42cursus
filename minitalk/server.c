/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:28:34 by akroll            #+#    #+#             */
/*   Updated: 2022/06/27 15:55:14 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sighandler(int signum)
{
	printf("SIGUSR1 received!\n");
}

int main()
{
	pid_t my_pid;
	struct sigaction sigact;

	my_pid = getpid();
	printf("pid: %d\n", my_pid);
	sigact.sa_handler = sighandler;

	if (sigaction(SIGUSR1, &sigact, NULL) == -1)
		perror("signal");

	while (1)
		pause();
	// while (!usr_interrupt)
		// sleep (1);

}
