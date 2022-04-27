/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:22:31 by akroll            #+#    #+#             */
/*   Updated: 2022/04/20 14:18:01 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

/*
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
*/

int	count_arguments(const char *format)
{
	int		num_args;
	int		i;

	num_args = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '%')
			num_args++;
		i++;
	}
	return (num_args);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		i;

	i = 0;
	//initialize list
	va_start(list, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
			printf("found %%%c\n", format[i + 1]);

		/* Get next argument value. */
		// this_arg = va_arg(list, type); /* va_arg() macro expands to an expression that has the type and value of the next argument in the call */
		// process(this_arg);
		i++;
	}
	va_end(list); /* finished argument processing */

	return (count_arguments(format));
}

int main()
{
	ft_printf("hi %d, %c, %s, %x", 6, 'c', "string", 26);

	return (0);
}