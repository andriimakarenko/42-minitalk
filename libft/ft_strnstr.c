/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 21:18:29 by amakaren          #+#    #+#             */
/*   Updated: 2018/12/05 22:42:23 by amakaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SLN ft_strlen
#define SIAPS ft_strisatposstr
#include "libft.h"

static int		ft_strisatposstr(const char *s1, const char *s2, size_t pos)
{
	size_t	i;

	i = 0;
	while (s2[i])
	{
		if (s1[pos + i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

char			*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		i;
	size_t		s2len;
	char		*str1;

	if (*s2 == '\0' && len == 0)
		return ((char*)s1);
	if (len < 1 || SLN(s1) < SLN(s2))
		return (NULL);
	if (*s1 && !(*s2))
		return ((char*)s1);
	s2len = SLN(s2);
	if (len > SLN(s1))
		return (ft_strstr(s1, s2));
	str1 = (char*)s1;
	i = 0;
	while (str1[i] && (i + s2len <= len))
	{
		if (str1[i] == *s2 && SIAPS(s1, s2, i))
			return ((char*)s1 + i);
		i++;
	}
	return (NULL);
}
