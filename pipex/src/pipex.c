/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvu <vvu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:38:57 by vvu               #+#    #+#             */
/*   Updated: 2023/05/20 11:32:43 by vvu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_fd(char **av, int file)
{
	int	fd;

	fd = 0;
	if (file == 0)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			error_code(av[1]);
	}
	else if (file == 1)
	{
		fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			error_code(av[4]);
	}
	return (fd);
}

void	child(char **av, char **ev, int *pipefd)
{
	int		fd;
	pid_t	pid;

	pid = fork();
	fd = 0;
	if (pid < 0)
		error_code(NULL);
	if (pid == 0)
	{
		fd = open_fd(av, 0);
		close(pipefd[0]);
		dup2(fd, 0);
		dup2(pipefd[1], 1);
		close(pipefd[1]);
		exec(av[2], ev);
	}
	close(fd);
}

void	parent(char **av, char **ev, int *pipefd)
{
	int		fd;
	pid_t	pid;

	pid = fork();
	fd = 0;
	if (pid < 0)
		error_code(NULL);
	if (pid == 0)
	{
		fd = open_fd(av, 1);
		close(pipefd[1]);
		dup2(fd, 1);
		dup2(pipefd[0], 0);
		close(pipefd[0]);
		exec(av[3], ev);
	}
	close(fd);
}

int	main(int ac, char **av, char **ev)
{
	int	pipefd[2];
	int	status;

	errno = 0;
	if (ac != 5)
		error_code("Usage: ./pipex file1 \"cmd1\" \"cmd2\" file2\n");
	if (pipe(pipefd) == -1)
		error_code(NULL);
	child(av, ev, pipefd);
	parent(av, ev, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
	return (0);
}
