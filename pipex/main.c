/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:06:53 by akroll            #+#    #+#             */
/*   Updated: 2022/06/22 16:49:22 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	int		fd[2];
	int		fd_file1;
	int		fd_file2;
	pid_t	pid;
	pid_t	pid2;
	char	*arguments[] = {"/bin/bash", "-c", argv[2], "-c", argv[3], 0};

	fd_file1 = open(argv[1], O_RDONLY);
	printf("fd file1: %d\n", fd_file1);
	fd_file2 = open(argv[4], O_WRONLY | O_CREAT, 00700);
	printf("fd file2: %d\n", fd_file2);

	if (argc != 5)
	{
		printf("Invalid number of arguments\n");
		return (1);
	}

// The pipe() call must be made BEFORE a call to fork(), or the descriptors will not be inherited by the child!
	if (pipe(fd) == -1)
		return (1);
	if ((pid = fork()) == -1)
	{
		perror("fork pid");
		return (1);
	}
	if (pid == 0)	// child process
	{
		close(fd[0]);
		dup2(fd_file1, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd_file1);
		close(fd[1]);
		execve("/bin/bash", arguments, 0);
	}
	if ((pid2 = fork()) == -1)
	{
		perror("fork pid2");
		return (1);
	}
	if (pid2 == 0)	// child process
	{
		waitpid(pid, 0, 0);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		dup2(fd_file2, STDOUT_FILENO);
		close(fd_file2);
		close(fd[0]);
		execve("/bin/bash", &arguments[2], 0);

		exit(0);
	}
	close(fd[0]);
	close(fd[1]);
	close(fd_file1);
	close(fd_file2);
	return (0);
}
