/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:47:32 by akroll            #+#    #+#             */
/*   Updated: 2022/05/09 15:38:28 by akroll           ###   ########.fr       */
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

size_t	get_length(const char *string)
{
	size_t	len;

	len = 0;
	while (string != NULL && (string[len] != '\0' && string[len] != '\n'))
		len++;
	return (len);
}

int	ft_strchr_bool(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s != '\0')
	{
		if (*s == (unsigned char)c)
			break ;
		s++;
	}
	return (*s == (unsigned char)c);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*concat_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	concat_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!concat_str)
		return (NULL);
	while (s1[i] != '\0')
	{
		concat_str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		concat_str[i] = s2[j];
		i++;
		j++;
	}
	concat_str[i] = '\0';
	free(s1);
	return (concat_str);
}

char *update_string(char *string)
{
	size_t	i;
	size_t	j;
	char	*shortened_str;

	i = 0;
	j = 0;
	while (string[i] != '\0' && string[i] != '\n')
		i++;
	if (string[i] == '\0')
	{
		free(string);
		return (NULL);
	}
	shortened_str = malloc(ft_strlen(string + i) + 1);
	if (shortened_str == NULL)
		return (NULL);
	while (string[++i] != '\0')
	{
		shortened_str[j] = string[i];
		j++;
	}
	shortened_str[j] = '\0';
	free(string);
	return (shortened_str);
}

static char	*copy_line(char *static_string)
{
	size_t	length;
	size_t	i;
	char	*string_out;

	i = 0;
	length = get_length(static_string);
	string_out = malloc(length * sizeof(char) + 1);
	if (string_out == NULL)
		return (NULL);
	while (i < length)
	{
		string_out[i] = static_string[i];
		i++;
	}
	if (static_string[i] == '\n')
		string_out[i] = '\n';
	string_out[++i] = '\0';
	return (string_out);
}

static char	*read_to_static(int fd, char *static_string)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr_bool(static_string, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[BUFFER_SIZE] = '\0';
		// printf("buffer: %s\n", buffer);
		static_string = ft_strjoin(static_string, buffer);
	}
	free(buffer);
	return (static_string);
}

char *get_next_line(int fd)
{
	static char *static_string;
	char		*string_out;
	// ssize_t		length;
	// ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	static_string = read_to_static(fd, static_string);
	if (static_string == NULL)
		return (NULL);
	string_out = copy_line(static_string);
	static_string = update_string(static_string);
	// printf("out: %s, %p\n", string_out, string_out);

	return (string_out);
}

// int	main()
// {
// 	int		fd;
// 	char	*output;

// 	fd = open("test.txt", O_RDONLY);
// 	output = get_next_line(fd);
// 	printf("output: %s\n", output);
// 	free(output);

// 	output = get_next_line(fd);
// 	printf("output: %s\n", output);
// 	free(output);

// 	system("leaks a.out");
// 	return (0);
// }
