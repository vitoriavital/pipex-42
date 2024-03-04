/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_multiple.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 15:12:07 by mavitori          #+#    #+#             */
/*   Updated: 2024/03/04 16:46:33 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static void	child_process_middle(int *pipe_fd, char *cmd, int input_fd)
{
	int	status;

	close(pipe_fd[0]);
	if (input_fd == -1)
		exit(EXIT_FAILURE);
	status = check_cmd(cmd);
	if (status == 0)
	{
		if (validate_input(pipe_fd) == -1)
			exit(EXIT_FAILURE);
		close(pipe_fd[1]);
		execute_command(input_fd, cmd);
		close(input_fd);
		exit(status);
	}
	else
	{
		close(input_fd);
		close(pipe_fd[1]);
		exit(status);
	}
}

int	middle_process(int input_fd, char *cmd)
{
	int		pipe_fd[2];
	pid_t	pid;

	pid = validate_pipe_fork(pipe_fd);
	if (pid == -1)
	{
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(input_fd);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		child_process_middle(pipe_fd, cmd, input_fd);
	else
	{
		close(pipe_fd[1]);
		close(input_fd);
		return (pipe_fd[0]);
	}
	return (-1);
}
