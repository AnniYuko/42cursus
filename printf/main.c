/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:32:35 by akroll            #+#    #+#             */
/*   Updated: 2022/06/15 14:24:38 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>

int	main()
{
	int *p;
	int	printed_chars;

	printed_chars = 0;
	p = malloc(sizeof(int));
	printed_chars = ft_printf("percent %% \ninteger %%i %i \nchar %%c %c \nstring %%s %s \n", INT_MIN, 'w', "hi\nheilbronn");
	printed_chars += ft_printf("decimal %%d %d\nunsigned %%u %u\nhex %%x %x\nhex %%X %X\n", INT_MAX, UINT_MAX, 256, 256);
	printed_chars += ft_printf("%%p %p\n", &p);
	printf("------\n\t counted: %d\n", printed_chars);

	printf("\n-----PRINTF------ \n");
	printed_chars = printf("percent %% \ninteger %%i %i \nchar %%c %c \nstring %%s %s \n", INT_MIN, 'w', "hi\nheilbronn");
	printed_chars += printf("decimal %%d %d\nunsigned %%u %u\nhex %%x %x\nhex %%X %X\n", INT_MAX, UINT_MAX, 256, 256);
	printed_chars += printf("%%p %p\n", &p);
	printf("------\n\t counted: %d\n", printed_chars);

	// printf("\n\ntest: %#x\n%#X\n%x\n", 180150004, 180150004, 180150004);
	return (0);
}
