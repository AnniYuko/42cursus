/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:49:28 by akroll            #+#    #+#             */
/*   Updated: 2022/03/22 15:15:05 by akroll           ###   ########.fr       */
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
	int i;
	char character;

	i = 0;
	character = itoa(c);
	while (s[i])
	{
		if (s[i] == character)
			return(s[i]);
		i++;
	}
	return(NULL);
}
