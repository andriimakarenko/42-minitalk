/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 21:17:56 by amakaren          #+#    #+#             */
/*   Updated: 2018/12/05 22:34:50 by amakaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	needle;
	int		i;

	needle = (char)c;
	if (needle == '\0')
		return ((char *)s + ft_strlen(s));
	i = -1;
	while (s[++i])
		if (s[i] == needle)
			return ((char *)s + i);
	return (NULL);
}
