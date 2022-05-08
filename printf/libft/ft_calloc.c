/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:57:18 by akroll            #+#    #+#             */
/*   Updated: 2022/03/29 10:50:22 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	n_bytes;

	n_bytes = count * size;
	mem = malloc(n_bytes);
	if (!mem)
		return (NULL);
	ft_bzero(mem, n_bytes);
	return (mem);
}
