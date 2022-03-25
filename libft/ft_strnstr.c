/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:09:43 by akroll            #+#    #+#             */
/*   Updated: 2022/03/25 16:47:52 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	while (haystack[i] && i < len)
	{
		printf("while\n");
		if (haystack[i] == needle[0])
		{
			printf("haystack: %c\nneedle: %c\n", haystack[i], needle[0]);
			if (ft_memcmp(haystack + i, needle, 1) == 0)
				return ((char *)haystack + i);
		}
		i++;
	}
	return(NULL);
}

int main (void)
{
	char str1[] = "hello world";
	char str2[] = "wo";

	printf("%s\n", ft_strnstr(str1, str2, 10));
	return 0;
}
