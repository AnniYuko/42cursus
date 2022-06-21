/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:06:53 by akroll            #+#    #+#             */
/*   Updated: 2022/06/21 15:44:46 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	int		fd[2];
	pid_t	pid;
	pid_t	pid2;
	char	*arguments[] = {"/bin/bash", "-c", "ls -l", "-c", "wc -l", 0};

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
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve("/bin/bash", &arguments[0], 0);

		exit(0);
	}
	pid2 = fork();
	if (pid2 < 0)
		return (1);
	if (pid2 == 0)	// child process
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve("/bin/bash", &arguments[2], 0);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
