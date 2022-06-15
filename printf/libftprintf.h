/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:26:15 by akroll            #+#    #+#             */
/*   Updated: 2022/06/15 15:51:06 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

int		ft_printf(const char *str, ...);
int		ft_putstr_fd_count(char *s, int fd, int *count, char option);
int		ft_putchar_fd_count(char c, int fd, int *count);
void	ft_putnbr_fd_unsigned(unsigned int n, int fd, int *count);
void	ft_puthex_fd(unsigned long n, char option, int fd, int *count);
void	ft_put_next_arg(char option, va_list ap, int *count);

#endif
