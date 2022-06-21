/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:06:53 by akroll            #+#    #+#             */
/*   Updated: 2022/06/21 16:33:13 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int		fd[2];
	pid_t	pid;
	pid_t	pid2;
	char	*arguments[] = {"/bin/bash", "-c", argv[2], "-c", argv[3], 0};

	if (argc != 5)
	{
		printf("Invalid number of arguments\n");
		return (1);
	}
	printf("command: %s %s %s | %s %s\n", argv[0], argv[1], argv[2], argv[3], argv[4]);

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
		execve("/bin/bash", arguments, 0);

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
		exit(0);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
