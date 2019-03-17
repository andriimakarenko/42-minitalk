/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 21:18:08 by amakaren          #+#    #+#             */
/*   Updated: 2018/12/05 22:42:52 by amakaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	needle;
	int		i;
	char	*reslut;

	reslut = NULL;
	needle = (char)c;
	if (needle == '\0')
		return ((char *)s + ft_strlen(s));
	i = -1;
	while (s[++i])
		if (s[i] == needle)
			reslut = (char *)s + i;
	return (reslut);
}
