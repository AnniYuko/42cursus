/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:57:18 by akroll            #+#    #+#             */
/*   Updated: 2022/03/22 16:11:47 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(unsigned int count, unsigned int size)
{
	void *mem;
	unsigned int n;

	n = count * size;
	mem = malloc(n);
	if (!mem)
		return(NULL);

	ft_bzero(mem, n);
	return(mem);
}

//set errno to ENOMEM?
