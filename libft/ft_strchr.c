/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:49:28 by akroll            #+#    #+#             */
/*   Updated: 2022/03/29 10:04:06 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	- locate char (ASCII) in string
	- return pointer to char, otherwise NULL
	- if c is \0 the functions returns its position, since it is part of the string
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			break ;
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}
