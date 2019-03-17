/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 21:15:32 by amakaren          #+#    #+#             */
/*   Updated: 2018/12/05 22:29:55 by amakaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	if (n == 0 || dst == src)
		return (dst);
	d = (char*)dst;
	s = (const char*)src;
	i = -1;
	while (++i < n)
		d[i] = s[i];
	return (dst);
}
