/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:58:42 by mavitori          #+#    #+#             */
/*   Updated: 2024/03/01 10:54:36 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static int	start_process_heredoc(int fd_heredoc, char *cmd)
{
	int		pipe_fd[2];
	pid_t	pid;

	pid = validate_pipe_fork(pipe_fd);
	if (pid == -1)
		exit(EXIT_FAILURE);
	else if (pid == 0)
		child_process_start(pipe_fd, cmd, "/tmp/here_doc");
	else
	{
		close(pipe_fd[1]);
		return (pipe_fd[0]);
	}
	close(fd_heredoc);
	return (-1);
}

static void	loop_heredoc(char *line, t_data data, int fd_heredoc)
{
	while (1)
	{
		ft_putstr_fd("pipe heredoc> ", STDOUT_FILENO);
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strncmp(line, data.limiter, ft_strlen(data.limiter)) == 0)
		{
			free(line);
			line = NULL;
			break ;
		}
		ft_putstr_fd(line, fd_heredoc);
		ft_putstr_fd("\n", fd_heredoc);
		free(line);
		line = NULL;
	}
}

int	evaluate_heredoc(t_data data)
{
	int		status;
	int		i;
	int		fd_heredoc;
	char	*line;
	int		input;

	i = 0;
	status = 0;
	fd_heredoc = open("/tmp/here_doc", O_CREAT | O_WRONLY, 0644);
	if (fd_heredoc == -1)
	{
		perror("Error opening file");
		return (-1);
	}
	line = "";
	loop_heredoc(line, data, fd_heredoc);
	close(fd_heredoc);
	input = start_process_heredoc(fd_heredoc, (data.cmds)[0]);
	status = end_process(input, (data.cmds)[1], data.file1);
	if (unlink("/tmp/here_doc") == -1)
	{
		perror("Error unlinking file");
		return (-1);
	}
	return (status);
}
