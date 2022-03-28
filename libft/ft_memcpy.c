/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:34:16 by akroll            #+#    #+#             */
/*   Updated: 2022/03/28 10:17:10 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char *p_src;
	unsigned char *p_dest;
	size_t i;

	p_dest = dest;
	p_src = src;
	i = 0;
	while (p_src[i] && i < n)
	{
		p_dest[i] = p_src[i];
		i++;
	}
	return (dest);
}
