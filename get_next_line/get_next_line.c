/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:47:32 by akroll            #+#    #+#             */
/*   Updated: 2022/05/16 16:55:24 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*move_str(char *dest, char *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	while (dest[i] != '\0')
		dest[i++] = '\0';
	return (dest);
}

char	*split_line_from_static(char *static_str)
{
	size_t	length;
	char	*string_out;

	if (static_str == NULL)
		return (NULL);
	length = get_length(static_str);
	string_out = malloc(length * sizeof(char) + 1);
	if (string_out == NULL)
		return (NULL);
	ft_memcpy(string_out, static_str, length);
	string_out[length] = '\0';
	move_str(static_str, &static_str[length], ft_strlen(&static_str[length]));
	return (string_out);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*concat_str;
	int		length_s1;
	int		length_s2;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (s1 == NULL)
			return (NULL);
		*s1 = '\0';
	}
	if (*s2 == '\0')
		return (s1);
	length_s1 = ft_strlen(s1);
	length_s2 = ft_strlen(s2);
	concat_str = malloc(sizeof(char) * (length_s1 + length_s2) + 1);
	if (!concat_str)
		return (NULL);
	ft_memcpy(concat_str, s1, length_s1);
	ft_memcpy(concat_str + length_s1, s2, length_s2 + 1);
	free(s1);
	return (concat_str);
}

char	*read_line(int fd, char *static_string)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = 1;
	while (!ft_strchr_bool(static_string, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read == -1)
			return (NULL);
		buffer[bytes_read] = '\0';
		// printf("buffer: %s\n", buffer);
		static_string = ft_strjoin(static_string, buffer);
		if (static_string == NULL)
			return (NULL);
	}
	return (static_string);
}

char	*get_next_line(int fd)
{
	static char	*static_string;
	char		*string_out;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_string = read_line(fd, static_string);
	if (static_string == NULL)
		return (NULL);
	// printf("after reading: %s\n", static_string);
	string_out = split_line_from_static(static_string);
	if (string_out == NULL)
		return (NULL);
	if (*static_string == '\0')
	{
		free(static_string);
		static_string = NULL;
	}
	// printf("static after split: %s\n", static_string);
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

// 	output = get_next_line(fd);
// 	printf("output: %s\n", output);
// 	free(output);

// 	system("leaks a.out");
// 	return (0);
// }
