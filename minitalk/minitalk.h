/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:48:50 by akroll            #+#    #+#             */
/*   Updated: 2022/06/29 13:27:28 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
#define MINITALK_H

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	show_bits(unsigned int num, int num_of_bytes);
void	send_str_as_signals(pid_t pid, char *str);

#endif
