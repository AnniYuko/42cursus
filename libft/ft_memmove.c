/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:11:30 by akroll            #+#    #+#             */
/*   Updated: 2022/03/25 14:41:40 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	- source and destination are allowed to overlap (uses buffer)
	- doesn't check for '\0' in src, always copies len amount of bytes to dst
*/

void *ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char *p_src;
	unsigned char *p_dest;
	unsigned char buffer[len];
	size_t i;

	p_dest = dst;
	p_src = src;
	i = 0;
	ft_memcpy(buffer, p_src, len);
	while (i < len)
	{
		p_dest[i] = buffer[i];
		i++;
	}
	return (dst);
}
