/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:09:09 by akroll            #+#    #+#             */
/*   Updated: 2022/03/23 14:22:35 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlcpy(char *dest, const char *src, unsigned int destsize)
{
	unsigned int i;

	i = 0;
	while (i++ < (destsize - 1))
	{
		dest[i] = src[i];
	}
	if (destsize != 0)
		dest[i] = '\0';
	return(i);
}
