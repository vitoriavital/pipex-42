/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:42:16 by mavitori          #+#    #+#             */
/*   Updated: 2024/02/29 13:18:59 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

extern char	**environ;

int static	build_cmd_path(char *single_cmd, int result)
{
	char	*cmd_path;

	cmd_path = ft_strjoin("/bin/", single_cmd);
	if (access(cmd_path, F_OK) != 0)
	{
		free(cmd_path);
		result = ft_errors("command not found", single_cmd);
		return (result);
	}
	else if (access(cmd_path, X_OK) != 0)
	{
		free(cmd_path);
		result = ft_errors("Permission denied", single_cmd);
		return (result);
	}
	else if (access(cmd_path, F_OK | X_OK) != 0)
	{
		free(cmd_path);
		perror("access");
		return (-1);
	}
	free(cmd_path);
	return (0);
}

int	check_cmd(char *cmd)
{
	char	*single_cmd;
	int		result;

	single_cmd = split_cmd(cmd);
	result = 0;
	if (ft_strncmp(single_cmd, "exit", 5) == 0 || ft_strncmp(single_cmd,
			"env_var", 8) == 0)
	{
		free(single_cmd);
		return (0);
	}
	if (access(single_cmd, F_OK | X_OK) == 0)
	{
		free(single_cmd);
		return (0);
	}
	result = build_cmd_path(single_cmd, result);
	free(single_cmd);
	return (result);
}

int	execute_command(int file_fd, char *cmd)
{
	char	*argv[4];
	char	**envp;

	argv[0] = "/bin/sh";
	argv[1] = "-c";
	argv[2] = cmd;
	argv[3] = NULL;
	envp = environ;
	if (dup2(file_fd, STDIN_FILENO) == -1)
	{
		perror("dup2");
		return (-1);
	}
	if (execve("/bin/sh", argv, envp) == -1)
	{
		perror("execve");
		return (-1);
	}
	return (0);
}
