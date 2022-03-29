/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:09:09 by akroll            #+#    #+#             */
/*   Updated: 2022/03/29 12:26:03 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	- copies chars from src to dest
	- returns total length of string it tried to create (src length)
	- destsize should have room for '\0'
	- null-termination is guaranteed
	- undefined behaviour if strings overlap
*/

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;

	i = 0;
	ft_memcpy(dest, src, destsize - 1);
	if (destsize != 0)
		dest[destsize] = '\0';
	return (ft_strlen(src));
}
