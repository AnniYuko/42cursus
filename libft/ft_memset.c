/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:25:34 by akroll            #+#    #+#             */
/*   Updated: 2022/03/23 10:57:38 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	- len is the amount of bytes
	- c is converted to unsigned char
	- len amount of chars are written to string b
*/

void	*ft_memset(void *b, int c, unsigned int len)
{
	unsigned char *p;
	unsigned int i;

	p = b;
	i = 0;
	while (i < len)
	{
		p[i] = c;
		i++;
	}
	return(b);
}
