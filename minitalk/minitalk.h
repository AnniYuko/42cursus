/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:48:50 by akroll            #+#    #+#             */
/*   Updated: 2022/07/19 11:48:57 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>
# include "libft/libft.h"



int		sigaction_init(struct sigaction *sigact);
void	send_str_as_signals(pid_t server_pid, char character);
void	server_feedback(int signum);
void	signal_handler(int signum, siginfo_t *info, void *context);

#endif
