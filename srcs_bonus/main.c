/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:52:06 by mavitori          #+#    #+#             */
/*   Updated: 2024/02/29 17:23:54 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex_bonus.h"

static int	evaluate(t_data data, int n)
{
	int	input;
	int	status;
	int	i;

	i = 0;
	input = start_process(data.file1, (data.cmds)[i++]);
	while ((i + 1) < (n - 3))
	{
		input = middle_process(input, (data.cmds)[i++]);
	}
	status = end_process(input, (data.cmds)[i], data.file2);
	return (status);
}

static void	initialize(char **argv, t_data *data, int n)
{
	data->cmds = &argv[2];
	data->file1 = argv[1];
	data->file2 = argv[n -1];
	data->here_doc = 0;
}

static void	initialize_heredoc(char **argv, t_data *data, int n)
{
	data->cmds = &argv[3];
	data->file1 = argv[n - 1];
	data->here_doc = 1;
	data->limiter = argv[2];
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		status;

	if (argc == 6 && ft_strncmp(argv[1], "here_doc", 10) == 0)
	{
		initialize_heredoc(argv, &data, argc);
		status = evaluate_heredoc(data);
		return (status);
	}
	else if (argc >= 5)
	{
		initialize(argv, &data, argc);
		status = evaluate(data, argc);
		return (status);
	}
	else
		exit(EXIT_FAILURE);
	return (0);
}
