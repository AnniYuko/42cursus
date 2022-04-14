/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:48:46 by akroll            #+#    #+#             */
/*   Updated: 2022/04/14 13:15:10 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	skip_delimiter_characters(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] == c)
	{
		i++;
	}
	return (i);
}

static unsigned int	iterate_word(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static unsigned int	count_strings(char const *s, char c)
{
	unsigned int	i;
	unsigned int	num_words;
	unsigned int	len;

	i = 0;
	num_words = 0;
	len = 0;
	while (s[i] != '\0')
	{
		i += skip_delimiter_characters(&s[i], c);
		len = iterate_word(&s[i], c);
		i += len;
		if (len > 0)
			num_words++;
	}
	return (num_words);
}

static char	*free_array(char **array, unsigned int *k)
{
	unsigned int	i;

	if (array[*k] == NULL)
	{
		i = 0;
		while (array[i] != NULL)
		{
			free(array[i++]);
		}
		free(array);
		return (NULL);
	}
	return (array[*k]);
}

char	**ft_split(char const *s, char c)
{
	char			**split_array;
	unsigned int	string_len;
	unsigned int	i;
	unsigned int	k;

	if (s == NULL)
		return (NULL);
	split_array = malloc((count_strings(s, c) + 1) * sizeof(char *));
	if (split_array == NULL)
		return (NULL);
	i = 0;
	k = 0;
	split_array[count_strings(s, c)] = NULL;
	while (k < count_strings(s, c))
	{
		i += skip_delimiter_characters(&s[i], c);
		string_len = iterate_word(&s[i], c);
		i += string_len;
		split_array[k] = malloc((string_len + 1) * sizeof(char));
		if (free_array(split_array, &k) == NULL)
			return (NULL);
		ft_strlcpy(split_array[k], &s[i] - string_len, string_len + 1);
		k++;
	}
	return (split_array);
}
