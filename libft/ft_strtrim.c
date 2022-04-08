/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:02:22 by akroll            #+#    #+#             */
/*   Updated: 2022/04/08 11:58:17 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	skip_charset_from_start(char const *s1, char const *set)
{
	unsigned int	i;

	i = 0;
	while (ft_strchr(set, s1[i]) != NULL)
	{
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str_trimmed;
	unsigned int	i;
	unsigned int	count;
	unsigned int	len;

	i = 0;
	count = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	i = skip_charset_from_start(s1, set);
	while (ft_strchr(set, s1[len]) != NULL && len > i)
	{
		len--;
	}
	count = (&s1[len] + 1) - &s1[i];
	str_trimmed = malloc((count + 1) * sizeof(char));
	if (str_trimmed == NULL)
		return (NULL);
	ft_strlcpy(str_trimmed, &s1[i], count + 1);
	return (str_trimmed);
}
