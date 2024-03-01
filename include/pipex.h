/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:13:04 by mavitori          #+#    #+#             */
/*   Updated: 2024/02/29 16:49:23 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* libft */
# include "../lib/libft/include/get_next_line.h"
# include "../lib/libft/include/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_data
{
	char	*cmd1;
	char	*cmd2;
	char	*file1;
	char	*file2;
}			t_data;

int			execute_command(int file_fd, char *cmd);
int			open_file(char *file);
int			start_process(char *file, char *cmd);
int			end_process(int input_fd, char *cmd, char *output_file);
int			ft_errors(char *message, char *cmd);
int			check_cmd(char *cmd);
char		*split_cmd(char *str);
int			validate_output(char *output_file);
int			validate_input(int *pipe_fd);
int			validate_pipe_fork(int fd[2]);
int			ft_error_open(void);

#endif
