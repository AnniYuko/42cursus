/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:26:55 by akroll            #+#    #+#             */
/*   Updated: 2022/04/21 16:44:53 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"
#include <stdio.h>
#include <limits.h>

// void	ft_puthex_fd(void *p, int fd)
// {
// 	char	*hex_num;
// 	int		num
// 	ft_putstr_fd(hex_num);
// }

void	ft_putnbr_unsigned_fd(unsigned int n, int fd)
{
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putnbr_unsigned_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + '0', fd);
	}
}

void	ft_puthex_fd(unsigned int n, char option, int fd)
{
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else if ((n >= 10 && n <= 16) && option == 'x')
		ft_putchar_fd('a' + (n - 10), fd);
	else if ((n >= 10 && n <= 16) && option == 'X')
		ft_putchar_fd('A' + (n - 10), fd);
	else
	{
		ft_puthex_fd(n / 16, option, fd);
		ft_puthex_fd(n % 16, option, fd);
	}
}

void	ft_put_next_arg(char option, va_list ap)
{
	if (option == '%')
		ft_putchar_fd('%', 1);
	if (option == 'c')
		ft_putchar_fd((char)va_arg(ap, int), 1);
	else if (option == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	// else if (option == 'p')
	// 	ft_puthex_fd(va_arg(ap, void *), 1);
	else if (option == 'd' || option == 'i')
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (option == 'u')
		ft_putnbr_unsigned_fd(va_arg(ap, unsigned int), 1);
	else if (option == 'x' || option == 'X')
	{
		ft_putstr_fd("0x", 1);
		ft_puthex_fd(va_arg(ap, unsigned int), option, 1);
	}

}

int	ft_printf2(const char *str, ...)
{
	int	i;
	va_list	ap;

	i = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_put_next_arg(str[i], ap);
		}
		else
			ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(ap);
	return (0);
}

int	main()
{
	ft_printf2("percent %% \ninteger %i \nchar %c \nstring %s \ndecimal %d\nunsigned %u\nhex %x\nHEX %X\n%%x should be: 0xa1b4cd6ef9\n", INT_MIN, '.', "heilbronn", INT_MAX, UINT_MAX, UINT_MAX, 694523096825);
	return (0);
}
