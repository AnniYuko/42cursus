/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:48:46 by akroll            #+#    #+#             */
/*   Updated: 2022/06/21 23:25:56 by akroll           ###   ########.fr       */
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

static void	free_array(char **split_array)
{
	while (*split_array != NULL)
	{
		free(*split_array);
		split_array++;
	}
	free(split_array);
}

char	**ft_split(char const *s, char c)
{
	char			**split_array;
	unsigned int	string_len;
	unsigned int	k;
	unsigned int	num_of_strings;

	k = 0;
	if (s == NULL)
		return (NULL);
	num_of_strings = count_strings(s, c);
	if (!(split_array = malloc((num_of_strings + 1) * sizeof(char *))))
		return (NULL);
	while (k < num_of_strings)
	{
		while (*s == c)
			s++;
		string_len = iterate_word(s, c);
		if (!(split_array[k] = ft_strldup(s, string_len))) {
			free_array(split_array);
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
// 	s = "_keep learning !_learn.code_repeat__";
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