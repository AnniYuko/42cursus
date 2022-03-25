/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:57:18 by akroll            #+#    #+#             */
/*   Updated: 2022/03/25 14:55:17 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	n;

	n = count * size;
	mem = malloc(n);
	if (!mem)
		return(NULL);
	ft_bzero(mem, n);
	return(mem);
}
//set errno to ENOMEM?
