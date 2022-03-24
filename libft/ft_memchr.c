/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:50:31 by akroll            #+#    #+#             */
/*   Updated: 2022/03/24 13:17:42 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//locate byte c in byte string s within the first n bytes

void *ft_memchr(const void *s, int c, unsigned int n)
{
	const unsigned char *p;

	p = s;
	while (n-- > 0)
	{
		if (*p == c)
			return((void *)p);
		p++;
	}
	return(NULL);
}
