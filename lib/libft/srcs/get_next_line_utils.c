/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:54:18 by mavitori          #+#    #+#             */
/*   Updated: 2024/02/29 17:29:29 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

void	ft_lstadd_back_gnl(t_content **list, t_content *new)
{
	t_content	*current;

	if (*list == NULL && new != NULL)
	{
		*list = new;
		return ;
	}
	if (new != NULL)
	{
		current = *list;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
}

t_content	*ft_lstnew_gnl(char character)
{
	t_content	*node;

	node = (t_content *)malloc(sizeof(t_content));
	if (node == NULL)
		return (NULL);
	node->character = character;
	node->next = NULL;
	return (node);
}

void	ft_strmap_gnl(char const *s, t_content **list)
{
	unsigned int	i;
	t_content		*node;

	i = 0;
	while (s[i])
	{
		node = ft_lstnew_gnl(s[i]);
		if (node == NULL)
		{
			return ;
		}
		ft_lstadd_back_gnl(list, node);
		i++;
	}
}

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	size_t			i;
	size_t			total;
	void			*mem;
	unsigned char	*str;

	i = 0;
	total = nmemb * size;
	mem = NULL;
	mem = malloc(total);
	if (mem == NULL)
		return (NULL);
	str = (unsigned char *)mem;
	while (i < total)
		str[i++] = '\0';
	return (mem);
}

void	ft_lstclear_gnl(t_content **list)
{
	t_content	*current;
	t_content	*next;

	current = *list;
	while (current != NULL)
	{
		next = current->next;
		current->character = 0;
		free (current);
			current = next;
	}
	*list = NULL;
}
