/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:02:22 by akroll            #+#    #+#             */
/*   Updated: 2022/07/04 14:26:08 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*str_trimmed;
	unsigned int	i;
	unsigned int	bytes_to_copy;
	unsigned int	len;

	i = 0;
	bytes_to_copy = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) != NULL && s1[i] != '\0')
		i++;
	while (ft_strchr(set, s1[len - 1]) != NULL && i < len)
		len--;
	if (i == len || len == 0)
		return (ft_strdup(""));
	bytes_to_copy = len - i;
	str_trimmed = malloc((bytes_to_copy + 1) * sizeof(char));
	if (str_trimmed == NULL)
		return (NULL);
	ft_strlcpy(str_trimmed, &s1[i], bytes_to_copy + 1);
	return (str_trimmed);
}
