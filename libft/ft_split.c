/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:38:34 by akroll            #+#    #+#             */
/*   Updated: 2022/04/13 15:34:52 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_next_word_length(char const *s, char c, int *i)
{
	int	word_len;

	word_len = 0;
	while (s[*i] == c)
		*i += 1;
	while (s[*i] != c && s[*i] != '\0')
	{
		*i += 1;
		word_len++;
	}
	return (word_len);
}

int	count_strings(char const *s, char c)
{
	int	i;
	int	num_words;
	int	len;

	i = 0;
	num_words = 0;
	len = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i++] != c && s[i] != '\0')
			len++;
		if (len > 0)
			num_words++;
	}
	return (num_words);
}

void	free_array(char **array)
{
	int	k;

	k = 0;
	while (array[k] != NULL)
	{
		free(array[k++]);
	}
	free(array);
}

char	**ft_split(char const *s, char c)
{
	char	**split_array;
	int		word_len;
	int		i;
	int		k;

	if (s == NULL)
		return (NULL);
	split_array = malloc((count_strings(s, c) + 1) * sizeof(char *));
	if (split_array == NULL)
		return (NULL);
	split_array[count_strings(s, c)] = NULL;
	i = 0;
	k = 0;
	while (k++ < count_strings(s, c))
	{
		word_len = get_next_word_length(s, c, &i);
		printf("word length: %d\n", word_len);
		split_array[k] = malloc((word_len + 1) * sizeof(char));
		if (split_array[k] == NULL)
		{
			free_array(split_array);
			return (NULL);
		}
		ft_strlcpy(split_array[k], s + i - word_len, word_len + 1);
	}
	return (split_array);
}

int	main()
{
	char *s;
	char **arr;
	int	i;
	int j;

	i = 0;
	j = 0;
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
//https://pythontutor.com/c.html#code=%0Aint%20%20%20%20get_next_word_length%28char%20const%20*s,%20char%20c,%20int%20*i%29%0A%7B%0A%20%20%20%20int%20%20%20%20word_len%3B%0A%0A%20%20%20%20word_len%20%3D%200%3B%0A%20%20%20%20while%20%28s%5B*i%5D%20%3D%3D%20c%29%0A%20%20%20%20%20%20%20%20*i%20%2B%3D%201%3B%0A%20%20%20%20while%20%28s%5B*i%5D%20!%3D%20c%20%26%26%20s%5B*i%5D%20!%3D%20'%5C0'%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20*i%20%2B%3D%201%3B%0A%20%20%20%20%20%20%20%20word_len%2B%2B%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20%28word_len%29%3B%0A%7D%0A%0Aint%20%20%20%20count_strings%28char%20const%20*s,%20char%20c%29%0A%7B%0A%20%20%20%20int%20%20%20%20i%3B%0A%20%20%20%20int%20%20%20%20num_words%3B%0A%20%20%20%20int%20%20%20%20len%3B%0A%0A%20%20%20%20i%20%3D%200%3B%0A%20%20%20%20num_words%20%3D%200%3B%0A%20%20%20%20len%20%3D%200%3B%0A%20%20%20%20while%20%28s%5Bi%5D%20!%3D%20'%5C0'%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20while%20%28s%5Bi%5D%20%3D%3D%20c%29%0A%20%20%20%20%20%20%20%20%20%20%20%20i%2B%2B%3B%0A%20%20%20%20%20%20%20%20while%20%28s%5Bi%2B%2B%5D%20!%3D%20c%20%26%26%20s%5Bi%5D%20!%3D%20'%5C0'%29%0A%20%20%20%20%20%20%20%20%20%20%20%20len%2B%2B%3B%0A%20%20%20%20%20%20%20%20if%20%28len%20%3E%200%29%0A%20%20%20%20%20%20%20%20%20%20%20%20num_words%2B%2B%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20%28num_words%29%3B%0A%7D%0A%0Avoid%20%20%20%20free_array%28char%20**array%29%0A%7B%0A%20%20%20%20int%20%20%20%20k%3B%0A%0A%20%20%20%20k%20%3D%200%3B%0A%20%20%20%20while%20%28array%5Bk%5D%20!%3D%20NULL%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20free%28array%5Bk%2B%2B%5D%29%3B%0A%20%20%20%20%7D%0A%20%20%20%20free%28array%29%3B%0A%7D%0A%0Achar%20%20%20%20**ft_split%28char%20const%20*s,%20char%20c%29%0A%7B%0A%20%20%20%20char%20%20%20%20**split_array%3B%0A%20%20%20%20int%20%20%20%20%20%20%20%20word_len%3B%0A%20%20%20%20int%20%20%20%20%20%20%20%20i%3B%0A%20%20%20%20int%20%20%20%20%20%20%20%20k%3B%0A%0A%20%20%20%20if%20%28s%20%3D%3D%20NULL%29%0A%20%20%20%20%20%20%20%20return%20%28NULL%29%3B%0A%20%20%20%20split_array%20%3D%20malloc%28%28count_strings%28s,%20c%29%20%2B%201%29%20*%20sizeof%28char%20*%29%29%3B%0A%20%20%20%20if%20%28split_array%20%3D%3D%20NULL%29%0A%20%20%20%20%20%20%20%20return%20%28NULL%29%3B%0A%20%20%20%20split_array%5Bcount_strings%28s,%20c%29%5D%20%3D%20NULL%3B%0A%20%20%20%20i%20%3D%200%3B%0A%20%20%20%20k%20%3D%200%3B%0A%20%20%20%20while%20%28k%2B%2B%20%3C%20count_strings%28s,%20c%29%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20word_len%20%3D%20get_next_word_length%28s,%20c,%20%26i%29%3B%0A%20%20%20%20%20%20%20%20printf%28%22word%20length%3A%20%25d%5Cn%22,%20word_len%29%3B%0A%20%20%20%20%20%20%20%20split_array%5Bk%5D%20%3D%20malloc%28%28word_len%20%2B%201%29%20*%20sizeof%28char%29%29%3B%0A%20%20%20%20%20%20%20%20if%20%28split_array%5Bk%5D%20%3D%3D%20NULL%29%0A%20%20%20%20%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20%20%20%20%20free_array%28split_array%29%3B%0A%20%20%20%20%20%20%20%20%20%20%20%20return%20%28NULL%29%3B%0A%20%20%20%20%20%20%20%20%7D%0A%20%20%20%20%20%20%20%20ft_strlcpy%28split_array%5Bk%5D,%20%26s%5Bi%5D%20-%20word_len,%20word_len%20%2B%201%29%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20%28split_array%29%3B%0A%7D%0A%0Aint%20%20%20%20main%28%29%0A%7B%0A%20%20%20%20char%20*s%3B%0A%20%20%20%20char%20**arr%3B%0A%20%20%20%20int%20%20%20%20i%3B%0A%20%20%20%20int%20j%3B%0A%0A%20%20%20%20i%20%3D%200%3B%0A%20%20%20%20j%20%3D%200%3B%0A%20%20%20%20s%20%3D%20%22UN_DEUX_TROIS%22%3B%0A%20%20%20%20printf%28%22input%3A%5Cn%5Ct%5C%22%25s%5C%22%5Cn%22,%20s%29%3B%0A%0A%20%20%20%20arr%20%3D%20ft_split%28s,%20'_'%29%3B%0A%0A%20%20%20%20printf%28%22%5Cnoutput%3A%5Cn%22%29%3B%0A%20%20%20%20while%20%28arr%5Bi%5D%20!%3D%20NULL%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20printf%28%22%5Ctstring%20%25d%3A%20%25s%5Cn%22,%20i,%20arr%5Bi%5D%29%3B%0A%20%20%20%20%20%20%20%20//%20while%20%28arr%5Bi%5D%5Bj%5D%20!%3D%20'%5C0'%29%0A%20%20%20%20%20%20%20%20//%20%7B%0A%20%20%20%20%20%20%20%20//%20%20%20%20%20printf%28%22%25c%22,%20arr%5Bi%5D%5Bj%5D%29%3B%0A%20%20%20%20%20%20%20%20//%20%20%20%20%20j%2B%2B%3B%0A%20%20%20%20%20%20%20%20//%20%7D%0A%20%20%20%20%20%20%20%20//%20printf%28%22%20----%20i%20is%20%25d,%20last%20j%20is%20%25d%5Cn%22,%20i,%20j%29%3B%0A%20%20%20%20%20%20%20%20i%2B%2B%3B%0A%20%20%20%20%20%20%20%20//%20j%20%3D%200%3B%0A%20%20%20%20%7D%0A%0A%20%20%20%20return%200%3B%0A%7D&mode=edit&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D
