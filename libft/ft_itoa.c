/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:34:30 by akroll            #+#    #+#             */
/*   Updated: 2022/04/06 15:48:25 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	count_digits(int n)
{
	unsigned int	digits;

	digits = 0;
	if (n < 0)
	{
		n *= -1;
		digits++;
	}
	while (n > 0)
	{
		n = n / 10;
		digits++;
	}
	return (digits);
}



char	*ft_itoa(int n)
{
	unsigned int	digits;
	char			*numbers_str;

	if (n == -2147483648)
			return ("-2147483648");
	digits = count_digits(n);
	numbers_str = malloc((digits + 1) * sizeof(char));
	if (numbers_str == NULL)
		return (NULL);
	numbers_str[digits] = '\0';
	if (n < 0)
	{
		numbers_str[0] = '-';
		digits--;
		n *= -1;
	}
	while (digits > 0)
	{
		numbers_str[digits] = (n % 10) + '0';
		n = n / 10;
		digits--;
	}
	return (numbers_str);
}

int	main()
{
	printf("%s\n", ft_itoa(-214748364));
}
