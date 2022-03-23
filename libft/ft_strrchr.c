/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:48:58 by akroll            #+#    #+#             */
/*   Updated: 2022/03/22 15:15:10 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	- same as strchr but returns pointer to LAST OCCURENCE of c
	- locate char (ASCII) in string
	- return pointer to char, otherwise NULL
	- if c is \0 the functions returns its position, since it is part of the string
*/

char	*ft_strchr(const char *s, int c)
{
	int i;
	char character;
	char *last_occ;

	i = 0;
	last_occ = NULL;
	character = itoa(c);
	while (s[i - 1])
	{
		if (s[i] == character)
			last_occ = s[i];
		i++;
	}
	return(last_occ);
}
