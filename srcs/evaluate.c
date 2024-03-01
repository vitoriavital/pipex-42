/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:52:58 by mavitori          #+#    #+#             */
/*   Updated: 2024/02/29 13:49:23 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	wait_process(pid_t pid)
{
	int	status;

	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{
		return (WEXITSTATUS(status));
	}
	else
		return (-1);
	return (0);
}

static void	child_process_start(int *pipe_fd, char *cmd, char *file)
{
	int	file_fd;
	int	status;

	close(pipe_fd[0]);
	if (validate_input(pipe_fd) == -1)
		exit(EXIT_FAILURE);
	close(pipe_fd[1]);
	file_fd = open_file(file);
	if (file_fd == -1)
		exit(EXIT_FAILURE);
	status = check_cmd(cmd);
	if (status == 0)
	{
		execute_command(file_fd, cmd);
		close(file_fd);
		exit(status);
	}
	else
	{
		close(file_fd);
		exit(status);
	}
}

int	start_process(char *file, char *cmd)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		status;

	pid = validate_pipe_fork(pipe_fd);
	status = 0;
	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0)
	{
		child_process_start(pipe_fd, cmd, file);
	}
	else
	{
		close(pipe_fd[1]);
		return (pipe_fd[0]);
	}
	return (-1);
}

static void	child_process_end(int input_fd, char *cmd, char *output_file,
		int *pipe_fd)
{
	int	output_fd;
	int	status;

	close(pipe_fd[0]);
	output_fd = validate_output(output_file);
	if (output_fd == -1)
		exit(EXIT_FAILURE);
	close(output_fd);
	status = check_cmd(cmd);
	if (status == 0)
	{
		execute_command(input_fd, cmd);
		exit(status);
	}
	else
		exit(status);
}

int	end_process(int input_fd, char *cmd, char *output_file)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		status;

	status = 0;
	pid = validate_pipe_fork(pipe_fd);
	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0)
	{
		child_process_end(input_fd, cmd, output_file, pipe_fd);
	}
	else
	{
		close(pipe_fd[1]);
		status = wait_process(pid);
		if (status != 0)
			return (status);
		close(pipe_fd[0]);
	}
	return (status);
}
