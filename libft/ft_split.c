/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:48:46 by akroll            #+#    #+#             */
/*   Updated: 2022/06/21 12:09:50 by akroll           ###   ########.fr       */
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

char	*ft_strldup(const char *s1, int len)
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

static char	*free_array(char **array, unsigned int *k)
{
	unsigned int	i;

	if (array[*k] == NULL)
	{
		i = 0;
		while (array[i] != NULL)
		{
			free(array[i]);
			i++;
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
	unsigned int	num_of_strings;

	if (s == NULL)
		return (NULL);
	num_of_strings = count_strings(s, c);
	split_array = malloc((num_of_strings + 1) * sizeof(char *));
	if (split_array == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (k < num_of_strings)
	{
		while (s[i] == c)
			i++;
		string_len = iterate_word(&s[i], c);
		split_array[k] = ft_strldup(&s[i], string_len);
		if (free_array(split_array, &k) == NULL)
			return (NULL);
		i += string_len;
		k++;
	}
	split_array[k] = NULL;
	return (split_array);
}

int	main()
{
	char *s;
	char **arr;
	int	i;

	i = 0;
	s = "_42_is a cool !_place to be__";
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