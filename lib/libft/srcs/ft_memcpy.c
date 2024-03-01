/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:53:39 by mavitori          #+#    #+#             */
/*   Updated: 2024/02/28 15:47:07 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*destination;
	unsigned const char	*source;

	i = 0;
	destination = (unsigned char *)dest;
	source = (unsigned const char *)src;
	if (dest == 0 && src == 0)
		return (dest);
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dest);
}
