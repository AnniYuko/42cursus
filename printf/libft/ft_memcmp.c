/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:33:57 by akroll            #+#    #+#             */
/*   Updated: 2022/04/15 12:47:17 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	- compares byte strings s1 and s2
	- if strings are similar over length n, returns 0
	- if different, returns diff between first two differing bytes
	- caution: it does not stop if a string is smaller than n (ignores '\0')
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p_s1;
	const unsigned char	*p_s2;
	size_t				i;

	p_s1 = s1;
	p_s2 = s2;
	i = 0;
	while (n-- > 0)
	{
		if (p_s1[i] != p_s2[i])
			return (p_s1[i] - p_s2[i]);
		i++;
	}
	return (0);
}
