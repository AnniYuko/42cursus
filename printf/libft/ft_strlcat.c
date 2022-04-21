/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:15:44 by akroll            #+#    #+#             */
/*   Updated: 2022/04/19 14:22:04 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;
	size_t	start;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (destsize <= dest_len)
		start = destsize;
	else
	{
		start = dest_len;
		while (src[i] != '\0' && (start + i) < (destsize - 1))
		{
			dest[start + i] = src[i];
			i++;
		}
		dest[start + i] = '\0';
	}
	return (start + src_len);
}
