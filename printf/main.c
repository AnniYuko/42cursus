/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:32:35 by akroll            #+#    #+#             */
/*   Updated: 2022/06/15 18:47:06 by akroll           ###   ########.fr       */
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
	printed_chars = ft_printf(" %% \ninteger %%i %i \nchar %%c %c \nstring %%s %s \n", INT_MIN, 'w', "hi\bbpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentbpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercent\n\t\t");
	printed_chars += ft_printf("decimal %%d %d\nunsigned %%u %u\nhex %%x %x\nhex %%X %X\n", INT_MAX, UINT_MAX, 256, 256);
	printed_chars += ft_printf("%%p %p\n", &p);
	printf("------\n\t counted: %d\n", printed_chars);

	printf("\n-----PRINTF------ \n");
	printed_chars = ft_printf(" %% \ninteger %%i %i \nchar %%c %c \nstring %%s %s \n", INT_MIN, 'w', "hi\bbpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentbpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercentpercent\n\t\t");
	printed_chars += printf("decimal %%d %d\nunsigned %%u %u\nhex %%x %x\nhex %%X %X\n", INT_MAX, UINT_MAX, 256, 256);
	printed_chars += printf("%%p %p\n", &p);
	printf("------\n\t counted: %d\n", printed_chars);

	return (0);
}
