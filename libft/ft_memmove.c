/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:11:30 by akroll            #+#    #+#             */
/*   Updated: 2022/04/08 16:20:25 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	- source and destination are allowed to overlap
	- doesn't check for '\0' in src, always copies len amount of bytes to dst
	here: if src > dst, start copying from the end back to the start
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*p_src;
	unsigned char		*p_dest;

	p_dest = dst;
	p_src = src;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (p_dest > p_src)
	{
		while (len-- > 0)
		{
			p_dest[len] = p_src[len];
		}
	}
	else
		ft_memcpy(p_dest, p_src, len);
	return (dst);
}
