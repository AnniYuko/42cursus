/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:15:44 by akroll            #+#    #+#             */
/*   Updated: 2022/04/14 13:33:09 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;
	size_t	start;

	i = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (destsize <= destlen)
		start = destsize;
	else
	{
		start = destlen;
		while (src[i] != '\0' && (start + i) < (destsize - 1))
		{
			dest[start + i] = src[i];
			i++;
		}
		dest[start + i] = '\0';
	}
	return (start + srclen);
}
