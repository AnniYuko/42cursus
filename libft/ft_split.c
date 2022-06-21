/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:48:46 by akroll            #+#    #+#             */
/*   Updated: 2022/06/21 23:03:22 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static char	*ft_strldup(const char *s1, int len)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[len] = '\0';
	return (dest);
}


static unsigned int	count_strings(char const *s, char c)
{
	unsigned int	i;
	unsigned int	num_words;
	unsigned int	len;

	i = 0;
	num_words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		len = iterate_word(&s[i], c);
		i += len;
		if (len > 0)
			num_words++;
	}
	return (num_words);
}

char	**ft_split(char const *s, char c)
{
	char			**split_array;
	unsigned int	string_len;
	unsigned int	k;
	unsigned int	num_of_strings;

	if (s == NULL)
		return (NULL);
	num_of_strings = count_strings(s, c);
	split_array = malloc((num_of_strings + 1) * sizeof(char *));
	if (split_array == NULL)
		return (NULL);
	k = 0;
	while (k < num_of_strings)
	{
		while (*s == c)
			s++;
		string_len = iterate_word(s, c);
		split_array[k] = ft_strldup(s, string_len);
		if (split_array[k] == NULL)
		{
			while (*split_array != NULL)
			{
				free(*split_array);
				split_array++;
			}
			free(split_array);
			return (NULL);
		}
		s += string_len;
		k++;
	}
	split_array[k] = NULL;
	return (split_array);
}

// int	main()
// {
// 	char *s;
// 	char **arr;
// 	int	i;

// 	i = 0;
// 	s = "_42_is a cool !_place to be__";
// 	printf("input:\n\t\"%s\"\n", s);

// 	arr = ft_split(s, '_');

// 	printf("\noutput:\n");
// 	while (arr[i] != NULL)
// 	{
// 		printf("\tstring %d: %s\n", i, arr[i]);
// 		i++;
// 	}
// 	return 0;
// }