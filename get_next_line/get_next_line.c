/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:47:32 by akroll            #+#    #+#             */
/*   Updated: 2022/04/28 11:18:32 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

// void	*ft_calloc(size_t count, size_t size)
// {
// 	unsigned char	*mem;
// 	size_t			i;
// 	size_t			n_bytes;

// 	i = 0;
// 	n_bytes = count * size;
// 	mem = malloc(n_bytes);
// 	if (mem == NULL)
// 		return (NULL);
// 	while (i < n_bytes)
// 	{
// 		mem[i] = '\0';
// 		i++;
// 	}
// 	return (mem);
// }

char	*ft_strldup(const char *s1, size_t length)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc(sizeof(char) * (length + 1));
	if (dest == NULL)
		return (NULL);
	while (i < length)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[length] = '\0';
	return (dest);
}

int	newline_found(const char *buffer, size_t *bytes_til_newl)
{
	int i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			*bytes_til_newl = i;
			return (1);		/* true */
		}
		i++;
	}
	return (0);		/* false */
}

char *ft_strljoin(const char *buffer, char *string, size_t length)
{
	char	*new_joined_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_joined_str = malloc(ft_strlen(buffer) + length + 1);
	if (new_joined_str == NULL)
		return (NULL);
	while (string[i] != '\0')
	{
		new_joined_str[i] = string[i];
		i++;
	}
	while (buffer[j] != '\0' && j < length)
	{
		new_joined_str[i + j] = buffer[j];
		j++;
	}
	new_joined_str[i + j] = '\0';
	free(string);
	return (new_joined_str);
}

char *get_next_line(int fd)
{
	static char *str_after_newl;
	char		*buffer;
	char		*string_out;
	size_t		bytes_til_newl;
	size_t		bytes_read;

	string_out = ft_strldup("\0", 1);
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);

	// check static char* for text (til a newline)

	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		printf("\tbuffer: %s\n", buffer);
		if (newline_found(buffer, &bytes_til_newl))
		{
			string_out = ft_strljoin(buffer, string_out, bytes_til_newl + 1);		/* (+ 1) includes newline character */
			str_after_newl = ft_strldup(&buffer[bytes_til_newl + 1], BUFFER_SIZE - bytes_til_newl);
			break ;
		}
		else
			string_out = ft_strljoin(buffer, string_out, BUFFER_SIZE);
	}
	printf("static: %s\n", str_after_newl);
	return (string_out);
}

int	main()
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("output: %s\n", get_next_line(fd));
	printf("output: %s\n", get_next_line(fd));
}


/* issues:

- what if entire file is empty? return empty string?
- read has an error -> return NULL
- leaks

*/
