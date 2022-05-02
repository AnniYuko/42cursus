/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:47:32 by akroll            #+#    #+#             */
/*   Updated: 2022/05/02 18:00:51 by akroll           ###   ########.fr       */
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

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc(ft_strlen(s1) + 1);
	if (dest == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	get_length(const char *string)
{
	size_t	len;

	len = 0;
	while (string != NULL && (string[len] != '\0' && string[len] != '\n'))
		len++;
	return (len);
}

char *ft_strljoin(const char *added, char *string, size_t length)
{
	char	*new_joined_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (added == NULL)
		added = ft_strdup("\0");
	new_joined_str = malloc(ft_strlen(string) + length + 1);
	if (new_joined_str == NULL)
		return (NULL);
	while (string[i] != '\0')
	{
		new_joined_str[i] = string[i];
		i++;
	}
	while (added[j] != '\0' && j < length)
	{
		new_joined_str[i + j] = added[j];
		j++;
	}
	new_joined_str[i + j] = '\0';
	//free(string);
	string = NULL;
	return (new_joined_str);
}

char *get_next_line(int fd)
{
	static char *str_after_newl;
	char		*buffer;
	char		*string_out;
	size_t		length;
	//size_t		bytes_read;
	size_t		i;
	int			newline_found;

	string_out = ft_strdup("\0");
	buffer = ft_strdup("\0");
	i = 0;

	length = get_length(str_after_newl);	/* til \n or \0 */
	string_out = ft_strljoin(str_after_newl, string_out, length + 1);	/* (+ 1) includes newline character */
	str_after_newl += length;	/* move pointer to the end of what was read (could be deleted) */
	if (string_out[length] == '\n')
		return (string_out);

	while (*buffer != '\n')
	{
		read(fd, buffer, BUFFER_SIZE);
		buffer[BUFFER_SIZE] = '\0';
		printf("\tbuffer: %s\n", buffer);
		length = get_length(buffer);	/* til \n or \0 */
		string_out = ft_strljoin(buffer, string_out, length + 1);	/* (+ 1) includes newline character */
		printf("stored: %s\n", string_out);
		buffer += length;	/* move pointer to the end of what was read (could be deleted) */
		str_after_newl = ft_strdup(buffer + 1);
	}
	printf("static: %s\n", str_after_newl);
	//free(buffer);
	return (string_out);
}

int	main()
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("output: %s\n", get_next_line(fd));
	printf("output: %s\n", get_next_line(fd));
	printf("output: %s\n", get_next_line(fd));
	// printf("output: %s\n", get_next_line(fd));
}


/* issues:

- what if entire file is empty? return empty string?
- read has an error -> return NULL
- leaks

*/
