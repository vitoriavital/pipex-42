/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavitori <mavitori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:14:33 by mavitori          #+#    #+#             */
/*   Updated: 2024/02/28 15:47:07 by mavitori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t			i;
	unsigned char	value;
	unsigned char	*str;

	i = 0;
	value = (unsigned char)c;
	str = (unsigned char *)dest;
	while (i < n)
		str[i++] = value;
	return (dest);
}
