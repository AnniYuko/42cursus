/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:09:43 by akroll            #+#    #+#             */
/*   Updated: 2022/03/28 14:15:27 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	- returns first occurrence of needle (pointer to first char)
	- if needle is empty string, returns pointer to haystack
	- if needle is not found, returns NULL
	- at most len amount of chars are searched, stops if there is a '\0'
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
		{
			printf("haystack: %c\nneedle: %c\n", haystack[i], needle[0]);
			if (ft_memcmp(haystack + i, needle, 1) == 0)
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
