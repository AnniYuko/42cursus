/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:34:10 by akroll            #+#    #+#             */
/*   Updated: 2022/04/15 13:27:09 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	- compares null-terminated strings s1 and s2 but only n bytes
//	- return value is the difference of s1, s2
//	- using unsigned characters ('\200' > '\0')

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
