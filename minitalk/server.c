/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:28:34 by akroll            #+#    #+#             */
/*   Updated: 2022/06/29 13:57:39 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned int	convert_bits_to_byte(int b, int i)
{
	static unsigned char	byte;

	if (b == -1)
	{
		write(1, "Error: Not SIGUSR1 or SIGUSR2", 30);
		return (0);
	}
	if (i == 0)
		byte = 0;
	if (i < 8)
		byte |= b << (7 - i);
	return (byte);
}

void	signal_catcher(int signum, siginfo_t *info, void *context)
{
	int	b;
	static unsigned int	i;
	unsigned char	character;

	if (signum == SIGUSR1)
		b = 1;
	else if (signum == SIGUSR2)
		b = 0;
	character = convert_bits_to_byte(b, i);
	i += 1;
	if (i == 8)
	{
		write(1, &character, 1);
		i = 0;
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
