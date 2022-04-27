/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:47:32 by akroll            #+#    #+#             */
/*   Updated: 2022/04/27 19:04:52 by akroll           ###   ########.fr       */
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

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*mem;
	unsigned int	i;
	size_t			n_bytes;

	i = 0;
	n_bytes = count * size;
	mem = malloc(n_bytes);
	if (mem == NULL)
		return (NULL);
	while (i < n_bytes)
	{
		mem[i] = '\0';
		i++;
	}
	return (mem);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;
	int		length;

	i = 0;
	length = ft_strlen(s1);
	dest = malloc(sizeof(char) * (length + 1));
	if (dest == NULL)
		return (NULL);
	while (i < length)
	{
		dest[i] = s1[i];
		i++;
	}
	return (dest);
}

int	no_newline_found(const char *buffer)
{
	int i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			return (0);		/* false */
		i++;
	}
	return (1);		/* true */
}

char *add_buffer_chunk_to_string(const char *buffer, char *string)
{
	char	*new_joined_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_joined_str = malloc(ft_strlen(buffer) + ft_strlen(string) + 1);
	if (new_joined_str == NULL)
		return (NULL);
	while (string[i] != '\0')
	{
		new_joined_str[i] = string[i];
		i++;
	}
	while (buffer[j] != '\0')
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
	char	*buffer;
	char	*string_out;
	int		b;

	b = 0;
	string_out = ft_strdup("\0");
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);

	printf("buffer content\n");
	while (no_newline_found(buffer))
	{
		/* get return value = */ read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		printf("\t%d: %s\n", b, buffer);
		string_out = add_buffer_chunk_to_string(buffer, string_out);
		b++;
	}
	// newline found:


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

- static char *content_after_newline
- always copies entire buffer (should stop after newline)
- what if entire file is empty? return empty string?
- what happens if read returns 0? quit while loop and return (newstring)
- read has an error -> return NULL

*/