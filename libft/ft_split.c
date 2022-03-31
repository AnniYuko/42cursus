/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:38:34 by akroll            #+#    #+#             */
/*   Updated: 2022/03/31 19:30:26 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	skip_delimiter_characters(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] == c)
	{
		i++;
	}
	return (i);
}

unsigned int	iterate_word(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	count_strings(char const *s, char c)
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
		i += (len = iterate_word(&s[i], c));
		if (len > 0)
			num_words++;
	}
	return (num_words);
}

//get_string_len();

char	**ft_split(char const *s, char c)
{
	char			**split_array;
	unsigned int	num_strings;
	unsigned int	string_len;
	unsigned int	i;
	unsigned int	k;

	if (s == NULL)		//protect
		return (NULL);
	num_strings = count_strings(s, c);
	if ((split_array = malloc((num_strings + 1) * sizeof(char *))) == NULL)	//malloc and protect
		return (NULL);
	i = 0;
	k = 0;
	while (num_strings-- > 0)
	{
		i += skip_delimiter_characters(&s[i], c);
		i += (string_len = iterate_word(&s[i], c));
		split_array[k] = malloc((string_len + 1) * sizeof(char));
		ft_strlcpy(split_array[k], &s[i] - string_len, string_len + 1);
		k++;
	}
	split_array[i] = NULL;		// The array must end with a NULL pointer.
	return (split_array);
}

int	main()
{
	char *s;
	char **arr;
	//int	num_of_strings;
	int	i;

	i = 0;
	//num_of_strings = 5;
	s = "test string  ''''    .     23 ";
	printf("input:\n\t\"%s\"\n", s);

	arr = ft_split(s, ' ');

	printf("\noutput:\n");
	while (arr[i] != NULL)
	{
		printf("\tstring %d: ", i);
		printf("\"%s\"\n", arr[i]);
		i++;
	}

	return 0;
}
