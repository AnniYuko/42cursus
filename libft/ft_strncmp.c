/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 12:34:10 by akroll            #+#    #+#             */
/*   Updated: 2022/04/01 09:05:51 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0 || s1 == NULL || s2 == NULL)
		return (0);
	while (i < n && (s1[i] != '\0' && s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	if (s1[i] != s2[i])
		return (s1[i] - s2[i]);
	return (0);
}

/*
ft_strncmp:    [OK] [OK] [OK] [OK] [OK] [OK] [FAILED] [OK] [OK] [FAILED] [FAILED] [OK] [NO CRASH] [NO CRASH]
[fail]: your strncmp does not cast in unsigned char the diff
[fail]: your strncmp does not work with non ascii chars
[fail]: your strncmp does not work when s1 is contained in s2
[no crash]: your strncmp does not segfault when null parameter is sent
[no crash]: your strncmp does not segfault when null parameter is sent
*/
