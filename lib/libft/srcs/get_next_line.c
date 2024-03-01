/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:54:03 by mavitori          #+#    #+#             */
/*   Updated: 2024/02/29 17:30:32 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

int	ft_search_end(t_content **list, int mode)
{
	t_content	*current;
	int			i;
	int			nl;

	current = *list;
	i = 0;
	nl = 1;
	while (current != NULL && current->character != '\n')
	{
		current = current->next;
		i++;
	}
	if (current != NULL && current->character == '\n')
	{
		current = current->next;
		i++;
		nl = 0;
	}
	if (nl == 1 && mode == 0)
		return (0);
	return (i);
}

char	*build_line(t_content **list, int size)
{
	t_content	*current;
	t_content	*next;
	char		*line;
	int			i;

	current = *list;
	line = (char *)ft_calloc_gnl(size + 1, sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (current != NULL && i < size)
	{
		next = current->next;
		line[i] = current->character;
		free(current);
		current = next;
		i++;
	}
	*list = current;
	return (line);
}

char	*ft_helper(char *buffer, char *line, t_content **list)
{
	int	size;

	ft_strmap_gnl(buffer, list);
	size = ft_search_end(list, 0);
	if (size == 0)
		line = NULL;
	else if (size > 0)
		line = build_line(list, size);
	free(buffer);
	return (line);
}

char	*read_buffer(int fd, t_content **list)
{
	char	*buffer;
	int		result;
	int		size;
	char	*line;

	result = 0;
	buffer = (char *)ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	result = read(fd, buffer, BUFFER_SIZE);
	line = NULL;
	if (result < 0)
	{
		ft_lstclear_gnl(list);
		free(buffer);
		return (NULL);
	}
	if (result == 0 && *list != NULL)
	{
		size = ft_search_end(list, 1);
		line = build_line(list, size);
		free(buffer);
		return (line);
	}
	line = ft_helper(buffer, line, list);
	return (line);
}

char	*get_next_line(int fd)
{
	static t_content	*list;
	char				*line;

	line = NULL;
	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE >= 1)
	{
		line = read_buffer(fd, &list);
		while (line == NULL && list != NULL)
		{
			line = read_buffer(fd, &list);
		}
	}
	return (line);
}
