/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:47:32 by akroll            #+#    #+#             */
/*   Updated: 2022/05/04 16:26:02 by akroll           ###   ########.fr       */
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
	return (len + 1);	/* (+1) inlcudes '\0' or '\n' */
}

int	ft_strchr_bool(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			break ;
		s++;
	}
	return (*s == (unsigned char)c);
}

char *ft_strljoin(char *added, char *string, size_t length)
{
	char	*new_joined_str;
	size_t	i;
	size_t	j;

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
	while (/* added != NULL && */ added[j] != '\0' && j < length)
	{
		new_joined_str[i + j] = added[j];
		j++;
	}
	new_joined_str[i + j] = '\0';
	// free(added); //?
	free(string);
	string = NULL;
	return (new_joined_str);
}

char *shorten_string(char *string, size_t start)
{
	size_t	i;
	char	*shortened_str;

	i = 0;
	if (start == 0)
		return (string);
	shortened_str = malloc(ft_strlen(string + start) + 1);
	while (string[start + i] != '\0')
	{
		shortened_str[i] = string[start + i];
		i++;
	}
	string[start + i] = '\0';
	// if (string != NULL)
	// 	free(string);
	// string = NULL;
	return (shortened_str);
}

char *get_next_line(int fd)
{
	static char *str_after_newl;
	char		*buffer;
	char		*string_out;
	ssize_t		length;
	ssize_t		bytes_read;

	string_out = ft_strdup("\0");
	if (!str_after_newl)
		str_after_newl = ft_strdup("\0");
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;

	length = get_length(str_after_newl);						/* til \n or \0 */
	if (length > 0)
		string_out = ft_strljoin(str_after_newl, string_out, length);
		// printf("\tstring_out 1: %s, %p\n", string_out, string_out);
		str_after_newl = shorten_string(str_after_newl, length);
		// printf("\tstr_after_newl 1: %s, %p\n", str_after_newl, str_after_newl);
	while (!ft_strchr_bool(string_out, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[BUFFER_SIZE] = '\0';
		printf("buffer: %s\n", buffer);
		length = get_length(buffer);							/* til \n or \0 */
		string_out = ft_strljoin(buffer, string_out, length);
		// printf("\tstring_out 2: %s, %p\n", string_out, string_out);
		// printf("\tstatic old: %s, %p\n", str_after_newl, str_after_newl);
		if (bytes_read > length)
			str_after_newl = shorten_string(buffer, length);
		// printf("\tstatic shortened: %s, %p\n", str_after_newl, str_after_newl);
	}
	free(buffer);
	return (string_out);
}

int	main()
{
	int		fd;

	fd = open("test.txt", O_RDONLY);

	printf("output: %s\n", get_next_line(fd));
	printf("output: %s\n", get_next_line(fd));
	printf("output: %s\n", get_next_line(fd));
	system("leaks a.out");
	return (0);
}


/* issues:

- ? "pointer being freed was not allocated"
- leaks

*/
