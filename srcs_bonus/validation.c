/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:41:31 by mavitori          #+#    #+#             */
/*   Updated: 2024/02/29 15:20:35 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

int	validate_pipe_fork(int fd[2])
{
	pid_t	pid;

	if (pipe(fd) == -1)
	{
		perror("pipe");
		return (-1);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	return (pid);
}

int	validate_input(int *pipe_fd)
{
	if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2");
		return (-1);
	}
	return (0);
}

int	validate_output(char *output_file)
{
	int	output_fd;

	output_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (output_fd == -1)
	{
		perror("open");
		return (-1);
	}
	if (dup2(output_fd, STDOUT_FILENO) == -1)
	{
		perror("dup2");
		return (-1);
	}
	return (output_fd);
}
