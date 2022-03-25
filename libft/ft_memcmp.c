/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:33:57 by akroll            #+#    #+#             */
/*   Updated: 2022/03/25 14:09:26 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	- compares byte strings s1 and s2
	- if strings are similar over length n, returns 0
	- if different it returns the diff between first two differing bytes (treated as unsigned chars)
	- caution: it does not stop if a string is smaller than n (ignores '\0')
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *p_s1;
	const unsigned char *p_s2;
	unsigned int i;

	p_s1 = s1;
	p_s2 = s2;
	i = 0;
	while (i < n && p_s1[i] == p_s2[i])
	{
		i++;
	}
	#ifdef DEBUG_INFO
	if (n != i)
		printf("first non-matching byte: %d\n", i);
	printf("s1: %c = %d, s2: %c = %d\n", p_s1[i], p_s1[i], p_s2[i], p_s2[i]);
	#endif
	return (p_s1[i] - p_s2[i]);
}
