/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:48:50 by akroll            #+#    #+#             */
/*   Updated: 2022/07/04 14:21:45 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include "libft/libft.h"

void	send_str_as_signals(pid_t pid, char *str);
void	signal_catcher(int signum, siginfo_t *info, void *context);

#endif
