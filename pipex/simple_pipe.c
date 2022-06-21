/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 22:48:24 by akroll            #+#    #+#             */
/*   Updated: 2022/06/21 14:01:19 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	int		fd[2];
	pid_t	pid;
	char	message[] = "hi parent";
	char	readbuffer[30];

// The pipe() call must be made BEFORE a call to fork(), or the descriptors will not be inherited by the child!
	if (pipe(fd) == -1)
		return (1);
	pid = fork();	// a child process inherits any open file descriptors from the parent
	printf("%d\n", pid);
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
	else			// parent process
	{
		close(fd[1]);
		read(fd[0], readbuffer, sizeof(readbuffer));
		printf("received from pipe: %s\n", readbuffer);
	}
	return (0);
}
