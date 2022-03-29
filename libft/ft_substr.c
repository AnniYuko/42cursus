/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:50:01 by akroll            #+#    #+#             */
/*   Updated: 2022/03/29 12:24:03 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	i = 0;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (i < len && s)
	{
		substr[i] = s[start + i];
		i++;
	}
	if (len != 0)
		substr[i] = '\0';
	return (substr);
}
