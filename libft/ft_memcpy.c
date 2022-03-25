/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:34:16 by akroll            #+#    #+#             */
/*   Updated: 2022/03/25 13:28:25 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void *ft_memcpy(void *dest, const void *src, unsigned int n)
{
	const unsigned char *p_src;
	unsigned char *p_dest;
	unsigned int i;

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
