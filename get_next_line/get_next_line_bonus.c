/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:53:49 by akroll            #+#    #+#             */
/*   Updated: 2022/05/17 09:03:34 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	char	*buffer;
	int		bytes_read;

	buffer = malloc(BUFFER_SIZE * sizeof(char) + 1);
	if (buffer == NULL)
		return (NULL);
	while (!ft_strchr_bool(static_string, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read == -1)
			return (free(buffer), NULL);
		buffer[bytes_read] = '\0';
		static_string = ft_strjoin(static_string, buffer);
		if (static_string == NULL)
			return (free(buffer), NULL);
	}
	free(buffer);
	return (static_string);
}

char	*get_next_line(int fd)
{
	static char	*static_string[OPEN_MAX];
	char		*string_out;

	if ((fd < 0 || BUFFER_SIZE <= 0) || fd > OPEN_MAX)
		return (NULL);
	static_string[fd] = read_line(fd, static_string[fd]);
	if (static_string[fd] == NULL)
		return (NULL);
	string_out = split_line_from_static(static_string[fd]);
	if (string_out == NULL)
		return (NULL);
	if (static_string[fd][0] == '\0')
	{
		free(static_string[fd]);
		static_string[fd] = NULL;
	}
	return (string_out);
}

// int	main()
// {
// 	int		fd_3;
// 	int		fd_4;
// 	char	*output;

// 	fd_3 = open("test.txt", O_RDONLY);
// 	// fd_4 = open("OpenOffice.odt", O_RDONLY);
// 	fd_4 = open("alternate_line_nl_no_nl", O_RDONLY);

// 	output = get_next_line(fd_3);
// 	printf("output %d: %s\n", fd_3, output);
// 	free(output);

// 	output = get_next_line(fd_4);
// 	printf("output %d: %s\n", fd_4, output);
// 	free(output);

// 	output = get_next_line(fd_3);
// 	printf("output %d: %s\n", fd_3, output);
// 	free(output);

// 	output = get_next_line(fd_4);
// 	printf("output %d: %s\n", fd_4, output);
// 	free(output);

// 	output = get_next_line(fd_3);
// 	printf("output %d: %s\n", fd_3, output);
// 	free(output);

// 	output = get_next_line(fd_4);
// 	printf("output %d: %s\n", fd_4, output);
// 	free(output);

// 	output = get_next_line(fd_3);
// 	printf("output %d: %s\n", fd_3, output);
// 	free(output);

// 	output = get_next_line(fd_3);
// 	printf("output %d: %s\n", fd_3, output);
// 	free(output);

// 	output = get_next_line(fd_3);
// 	printf("output %d: %s\n", fd_3, output);
// 	free(output);

// 	output = get_next_line(fd_4);
// 	printf("output %d: %s\n", fd_4, output);
// 	free(output);

// 	output = get_next_line(fd_4);
// 	printf("output %d: %s\n", fd_4, output);
// 	free(output);

// 	output = get_next_line(fd_4);
// 	printf("output %d: %s\n", fd_4, output);
// 	free(output);

// 	output = get_next_line(fd_4);
// 	printf("output %d: %s\n", fd_4, output);
// 	free(output);

// 	system("leaks a.out");
// 	return (0);
// }
