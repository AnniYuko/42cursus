/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:28:34 by akroll            #+#    #+#             */
/*   Updated: 2022/07/19 12:11:11 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile int	cli_received[2];

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
		ft_printf("%c", character);
		// if '\0' is received => "End of Message"
		if (!character)
			ft_printf("\n");
		position = 0;
		character = 0;
	}
	cli_received[0] = 1;
	cli_received[1] = info->si_pid;
}

int	main(void)
{
	pid_t				my_pid;
	struct sigaction	sigact;

	sigact.sa_sigaction = signal_handler;
	if (sigaction_init(&sigact) != 0)
		return (1);
	my_pid = getpid();
	ft_printf("pid: %d\n", my_pid);
	while (1)
	{
		while (cli_received[0] != 1)
			;
		cli_received[0] = 0;
		if (kill(cli_received[1], SIGUSR1) != 0)
				exit(EXIT_FAILURE);
	}
	return (0);
}
