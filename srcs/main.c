/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:52:06 by mavitori          #+#    #+#             */
/*   Updated: 2024/03/01 10:50:27 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	evaluate(t_data data)
{
	int	input2;
	int	status;

	input2 = start_process(data.file1, data.cmd1);
	status = end_process(input2, data.cmd2, data.file2);
	return (status);
}

static void	initialize(char **argv, t_data *data)
{
	data->cmd1 = argv[2];
	data->cmd2 = argv[3];
	data->file1 = argv[1];
	data->file2 = argv[4];
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		status;

	if (argc == 5)
	{
		initialize(argv, &data);
		status = evaluate(data);
		return (status);
	}
	else
		exit(EXIT_FAILURE);
	return (0);
}
