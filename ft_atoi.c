/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:18:06 by akroll            #+#    #+#             */
/*   Updated: 2022/02/11 18:21:27 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_atoi(char *str)
{
	int	i;
	int	m;
	int	number;

	i = 0;
	m = 0;
	number = 0;
	while(!(str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] == '-')
			m++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	if (m % 2)
		number *= - 1;
	return (number);
}
