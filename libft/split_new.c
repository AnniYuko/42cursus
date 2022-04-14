/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:48:46 by akroll            #+#    #+#             */
/*   Updated: 2022/04/14 13:01:54 by akroll           ###   ########.fr       */
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
	printf("count of strings: %u\n", (count_strings(s, c)));
	i = 0;
	k = 0;
	split_array[count_strings(s, c)] = NULL;
	while (k++ < count_strings(s, c))
	{
		printf("hi\n");
		i += skip_delimiter_characters(&s[i], c);
		printf("i: %u\n", i);
		string_len = iterate_word(&s[i], c);
		printf("string len: %u\n", string_len);
		split_array[k] = malloc((string_len + 1) * sizeof(char));
		if (free_array(split_array, &k) == NULL)
			return (NULL);
		printf("strlcpy: %zu\n", ft_strlcpy(split_array[k], &s[i], string_len + 1));
		i += string_len;
	}
	return (split_array);
}

int	main()
{
	char *s;
	char **arr;
	int	i;

	i = 0;
	s = "UN_DEUX_TROIS";
	printf("input:\n\t\"%s\"\n", s);

	arr = ft_split(s, '_');

	printf("\noutput:\n");
	while (arr[i] != NULL)
	{
		printf("\tstring %d: %s\n", i, arr[i]);
		i++;
	}
	return 0;
}
