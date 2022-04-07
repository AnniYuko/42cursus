/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 13:02:22 by akroll            #+#    #+#             */
/*   Updated: 2022/04/07 20:13:30 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// unsigned int	skip_charset(char const *s1, char const *set, int count)
// {
// 	unsigned int	i;
// 	unsigned int	direction;

// 	i = 0;
// 	if (count > 0)
// 		direction = 1;
// 	while (ft_strchr(set, s1[i]) != NULL)
// 	{
// 		if (direction == 1)
// 			i++;
// 		else
// 			i--;
// 	}
// 	return (i);
// }

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
	while (ft_strchr(set, s1[i]) != NULL)
	{
		i++;
	}
	while (ft_strchr(set, s1[len]) != NULL && len > 0)
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
