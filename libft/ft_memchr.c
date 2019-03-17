/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 21:16:15 by amakaren          #+#    #+#             */
/*   Updated: 2018/12/05 22:26:05 by amakaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	wanted;

	wanted = (unsigned char)c;
	i = -1;
	while (++i < n)
		if (((unsigned char*)s)[i] == wanted)
			return ((void *)s + i);
	return (NULL);
}
