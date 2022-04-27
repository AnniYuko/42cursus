/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:47:32 by akroll            #+#    #+#             */
/*   Updated: 2022/04/27 16:27:26 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// size_t	ft_strlen(const char *s)
// {
// 	size_t	len;

// 	len = 0;
// 	while (s[len] != '\0')
// 		len++;
// 	return (len);
// }

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

// char *add_buffer_chunk_to_string(const char *buffer, const char *string_out)
// {
// 	char *new_joined_str;

// 	new_joined_str = malloc(ft_strlen(buffer) + ft_strlen(string_out) + 1);

// 	free(string_out);
// 	return (new_joined_str);
// }

char *get_next_line(int fd)
{
	char	*buffer;
	char	*string_out;
	int		b;

	b = 0;
	string_out = "\0";		/* allowed to use stack? */
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);

	printf("buffer content\n");
	while (no_newline_found(buffer))
	{
		b++;
		/* get return value = */ read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		printf("\t%d: %s\n", b, buffer);
		//add_buffer_chunk_to_string(buffer, string_out);
	}
	// newline found:


	return (string_out);
}

int	main()
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("output: %s\n", get_next_line(fd));
}




/* issues:

- static char *content_after_newline
- always copies entire buffer (should stop after newline)
- what if entire file is empty? return empty string?
- what happens if read returns 0? quit while loop and return (newstring)
- read has an error -> return NULL

*/
