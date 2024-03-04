/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 13:59:46 by mavitori          #+#    #+#             */
/*   Updated: 2024/03/04 16:28:44 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	open_file(char *file, int fd)
{
	int	file_fd;

	file_fd = open(file, O_RDONLY);
	if (file_fd == -1)
	{
		ft_error_open();
		close(fd);
		return (-1);
	}
	return (file_fd);
}

char	*split_cmd(char *str)
{
	char	*space_ptr;
	size_t	length;
	char	*result;

	space_ptr = ft_strchr(str, ' ');
	if (space_ptr)
		length = (size_t)(space_ptr - str);
	else
		length = ft_strlen(str);
	result = (char *)malloc(length + 1);
	if (result == NULL)
		return (NULL);
	ft_memcpy(result, str, length);
	result[length] = '\0';
	return (result);
}
