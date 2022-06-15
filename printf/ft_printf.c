/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:26:55 by akroll            #+#    #+#             */
/*   Updated: 2022/06/15 15:39:24 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_put_next_arg(char option, va_list ap, int *count)
{
	if (option == '%')
		ft_putchar_fd_count('%', 1, count);
	else if (option == 'c')
		ft_putchar_fd_count((char)va_arg(ap, int), 1, count);
	else if (option == 's')
		ft_putstr_fd_count(va_arg(ap, char *), 1, count, option);
	else if (option == 'd' || option == 'i')
		ft_putstr_fd_count(ft_itoa(va_arg(ap, int)), 1, count, option);
	else if (option == 'u')
		ft_putnbr_fd_unsigned(va_arg(ap, unsigned int), 1, count);
	else if (option == 'x' || option == 'X' || option == 'p')
	{
		if (option == 'p')
			ft_putstr_fd_count("0x", 1, count, option);
		ft_puthex_fd(va_arg(ap, unsigned long), option, 1, count);
	}
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count_printed;
	va_list	ap;

	i = 0;
	count_printed = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			i++;
			ft_put_next_arg(str[i], ap, &count_printed);
		}
		else
			ft_putchar_fd_count(str[i], 1, &count_printed);
		i++;
	}
	va_end(ap);
	return (count_printed);
}
