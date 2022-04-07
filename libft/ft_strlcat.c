/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:15:44 by akroll            #+#    #+#             */
/*   Updated: 2022/04/01 09:06:38 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;

	i = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (destsize == 0)
		return (destlen + srclen);
	while (src[i] != '\0' && (i < (destsize - destlen - 1)))
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	if ((destlen + srclen) >= destsize)
		return (destsize);
	return (destlen + srclen);
}

/*
ft_strlcat:    [FAILED] [FAILED] [OK] [OK] [OK] [OK] [OK] [OK] [OK] [FAILED] [OK] [OK]
[fail]: your strlcat does not work with basic input
[fail]: your strlcat does not work with basic input
[fail]: your strlcat return value is false
*/
