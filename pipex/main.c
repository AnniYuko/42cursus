/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:06:53 by akroll            #+#    #+#             */
/*   Updated: 2022/06/20 16:24:46 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	int		fd[2];
	pid_t	pid;
	char	*arguments[] = {"/bin/bash", "-c", "ls -l", "-c", "wc -l", 0};

// The pipe() call must be made BEFORE a call to fork(), or the descriptors will not be inherited by the child!
	pipe(fd);
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
		execve("/bin/bash", &arguments[0], 0);

		exit(0);
	}
	else			// parent process
	{
		close(fd[1]);
		execve("/bin/bash", &arguments[2], 0);
	}
	return (0);
}
