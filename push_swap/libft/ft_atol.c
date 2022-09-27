/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 16:42:11 by akroll            #+#    #+#             */
/*   Updated: 2022/09/27 17:20:36 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	convert_num(const char *str, int sign, int i)
{
	long	nb;

	nb = 0;
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		if ((nb > __LONG_MAX__ / 10)
			|| (nb == __LONG_MAX__ / 10 && str[i] - '0' > 7))
		{
			if (sign == 1)
				return (__LONG_MAX__);
			else
				return (-__LONG_MAX__ - 1);
		}
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb);
}

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	nb;

	sign = 1;
	i = 0;
	while ((str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '-')
			sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	nb = convert_num(str, sign, i);
	return (sign * nb);
}
