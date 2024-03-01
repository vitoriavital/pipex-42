/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:29:27 by mavitori          #+#    #+#             */
/*   Updated: 2024/02/28 15:47:07 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*mem;

	mem = NULL;
	total = nmemb * size;
	mem = malloc(total);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, total);
	return (mem);
}
