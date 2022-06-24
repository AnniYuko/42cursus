/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:38:34 by akroll            #+#    #+#             */
/*   Updated: 2022/04/19 17:32:18 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static unsigned int	get_word_length(char const *s, char c)
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
		while (s[i] == c)
			i++;
		len = get_word_length(&s[i], c);
		i += len;
		if (len > 0)
			num_words++;
	}
	return (num_words);
}

static void	free_array(char **array)
{
	int	k;

	k = 0;
	while (array[k] != NULL)
	{
		free(array[k]);
		k++;
	}
	free(array);
}

static void	copy_word(char const *s, char c, char **split_array, int *k)
{
	int	word_len;
	int	i;

	i = 0;
	while (s[i] == c)
	{
		i += 1;
	}
	word_len = get_word_length(&s[i], c);
	printf("word length: %d\n", word_len);
	i += word_len;
	split_array[*k] = malloc((word_len + 1) * sizeof(char));
	if (split_array[*k] == NULL)
	{
		free_array(split_array);
		return ;
	}
	ft_strlcpy(split_array[*k], &s[i] - word_len, word_len + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**split_array;
	int		words;
	int		k;

	if (s == NULL)
		return (NULL);
	words = count_strings(s, c);
	split_array = malloc((words + 1) * sizeof(char *));
	if (split_array == NULL)
		return (NULL);
	split_array[words] = NULL;
	k = 0;
	while (k < words)
	{
		copy_word(s, c, split_array, &k);
		if (split_array[k] == NULL)
			return (NULL);
		k++;
	}
	return (split_array);
}

int	main()
{
	char *s;
	char **arr;
	int	i;

	i = 0;
	s = "_42_is a cool place to be_";
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
