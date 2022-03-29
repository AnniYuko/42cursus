/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:48:58 by akroll            #+#    #+#             */
/*   Updated: 2022/03/29 10:08:00 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	- same as strchr but returns pointer to LAST OCCURENCE of c
	- locate char (ASCII) in string
	- return pointer to char, otherwise NULL
	- if c is \0 the functions returns its position, since it is part of the string
*/

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last_occ;

	i = 0;
	last_occ = NULL;
	while (*s != '\0')
	{
		if (*s == c)
			last_occ = (char *)s;
		s++;
	}
	if (*s == c)
		last_occ = (char *)s;
	return (last_occ);
}
