/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:34:30 by akroll            #+#    #+#             */
/*   Updated: 2022/04/02 17:25:11 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_digits(int n)
{
	unsigned int	digits;

	digits = 0;
	while (n > 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}



char	*ft_itoa(int n)
{
	unsigned int	num_digits;
	char			*numbers_str;

	num_digits = 0;
	if (n == -2147483648)
			return ("-2147483648");
	if (n < 0)
	{
		num_digits++;
		n *= -1;
	}
	num_digits += count_digits(n);
	if ((numbers_str = malloc((num_digits + 1) * sizeof(char))) == NULL)
		return (NULL);

	return (numbers_str);
}


//number to ascii by (n)^size-i, i++, use modulo for getting right digit

