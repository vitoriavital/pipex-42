/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:13:04 by mavitori          #+#    #+#             */
/*   Updated: 2024/03/01 10:57:07 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
	char	**cmds;
	char	*file1;
	char	*file2;
	char	*limiter;
	int		here_doc;
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
int			wait_process(pid_t pid);
int			middle_process(int input_fd, char *cmd);
int			ft_error_open(void);
int			evaluate_heredoc(t_data data);
void		child_process_start(int *pipe_fd, char *cmd, char *file);

#endif
