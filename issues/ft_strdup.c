/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:50:17 by akroll            #+#    #+#             */
/*   Updated: 2022/03/25 14:49:23 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;

	dest = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	//If insufficient memory is available, NULL is returned and errno is set to ENOMEM?
	if (!dest)
		return(NULL);
	ft_strlcpy(dest, s1, sizeof(dest));
	return (dest);
}
