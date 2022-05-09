/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line-version-char-by-char.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:49:48 by akroll            #+#    #+#             */
/*   Updated: 2022/05/09 15:55:49 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

// where allocate buffer ?

read_next_buffersize(int fd, size_t len)
{
	if (bytes_read <= len)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		// reset counter (written bytes) to 0 ?
	}
	return (!(bytes_read == 0));
}

char	*read_to_static_string(int fd, char *static_string, int *len)
{
	while (read_next_buffersize(fd, len))
	{
		static_string = add_space_if_necessary(static_string);
		static_string[?] = buffer[len];
		if (buffer[len] == '\n')
			break ;
		len++;
	}
	static_string[?] = '\0';
	return ();
}

char	*copy_line(char *static_string, int len)
{
	return ();
}

char	*get_next_line(int fd)
{
	static char *static_string;
	char		*string_out;
	size_t		len;

	len = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_string = read_to_static_string(fd, static_string, &len);
	if (static_string == NULL)
		return (NULL);
	string_out = copy_line(static_string, len);
	//update static ?

	return (string_out);
}




int	main()
{
	int		fd;

	fd = open("test.txt", O_RDONLY);

	printf("output: %s\n", get_next_line(fd));
	printf("output: %s\n", get_next_line(fd));
	printf("output: %s\n", get_next_line(fd));

	// system("leaks a.out");
	return (0);
}
