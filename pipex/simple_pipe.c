/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:48:24 by akroll            #+#    #+#             */
/*   Updated: 2022/06/20 13:11:55 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv)
{
	int		fd[2];
	pid_t	pid;
	char	message[] = "hi parent";
	char	readbuffer[30];

	printf("argc: %d\n", argc);
	(void)argv;

// The pipe() call must be made BEFORE a call to fork(), or the descriptors will not be inherited by the child!
	pipe(fd);
	pid = fork();	// a child process inherits any open file descriptors from the parent
	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	if (pid == 0)	// child process
	{
		close(fd[0]);
		write(fd[1], message, strlen(message) + 1);
		exit(0);
	}
	else			// parent process, pid == 1
	{
		close(fd[1]);
		read(fd[0], readbuffer, sizeof(readbuffer));
		printf("received from pipe: %s\n", readbuffer);
	}
	return (0);
}
