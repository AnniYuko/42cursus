/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:28:34 by akroll            #+#    #+#             */
/*   Updated: 2022/06/27 15:51:21 by akroll           ###   ########.fr       */
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

	my_pid = getpid();
	printf("pid: %d\n", my_pid);

	if (signal(SIGUSR1, sighandler) != 0)
		perror("signal");

	while (1)
		pause();

}
