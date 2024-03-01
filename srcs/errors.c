/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:11:04 by mavitori          #+#    #+#             */
/*   Updated: 2024/02/29 16:49:37 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_errors(char *message, char *cmd)
{
	int	value;

	value = 0;
	if (ft_strncmp(message, "command not found", 19) == 0 || ft_strncmp(message,
			"Permission denied", 19) == 0)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd(cmd, STDERR_FILENO);
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(message, STDERR_FILENO);
		ft_putstr_fd("\n", STDERR_FILENO);
		if (ft_strncmp(message, "command not found", 19) == 0)
			value = 127;
		else
			value = 128;
	}
	return (value);
}

int	ft_error_open(void)
{
	ft_putstr_fd("pipex: input: No such file or directory\n", STDERR_FILENO);
	return (1);
}
