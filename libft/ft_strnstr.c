/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:09:43 by akroll            #+#    #+#             */
/*   Updated: 2022/03/30 16:28:29 by akroll           ###   ########.fr       */
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
	size_t	needle_len;

	i = 0;
	needle_len = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0] && (needle_len + i) <= len)
		{
			if (ft_memcmp(haystack + i, needle, needle_len) == 0)
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
