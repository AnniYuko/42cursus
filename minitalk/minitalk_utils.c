/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:21:54 by akroll            #+#    #+#             */
/*   Updated: 2022/07/18 19:25:41 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	sigaction_init(struct sigaction *sigact)
{
	sigemptyset(&sigact->sa_mask);
	sigaddset(&sigact->sa_mask, SIGUSR1);
	sigaddset(&sigact->sa_mask, SIGUSR2);
	sigact->sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, sigact, NULL) == -1
		|| sigaction(SIGUSR2, sigact, NULL) == -1)
	{
		write(1, "signal error\n", 14);
		return (1);
	}
	return (0);
}
