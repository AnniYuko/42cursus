/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:32:35 by akroll            #+#    #+#             */
/*   Updated: 2022/05/17 18:41:36 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>

int	main()
{
	int *p;

	p = malloc(sizeof(int));
	ft_printf("percent %% \ninteger %%i %i \nchar %%c %c \nstring %%s %s \n", INT_MIN, 'w', "heilbronn");
	ft_printf("decimal %%d %d\nunsigned %%u %u\nhex %%x %x\nhex %%X %X\n", INT_MAX, UINT_MAX, 180150004, 180150004);
	ft_printf("%%p %p\n", &p);

	printf("\nPRINTF: ----------- \n");
	printf("percent %% \ninteger %%i %i \nchar %%c %c \nstring %%s %s \n", INT_MIN, 'w', "heilbronn");
	printf("decimal %%d %d\nunsigned %%u %u\nhex %%x %x\nhex %%X %X\n", INT_MAX, UINT_MAX, 180150004, 180150004);
	printf("%%p %p\n", &p);
	return (0);
}
