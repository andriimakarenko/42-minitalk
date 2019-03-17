/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 21:22:45 by amakaren          #+#    #+#             */
/*   Updated: 2018/12/05 22:39:24 by amakaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		r;

	if (!(s1) || !(s2))
		return (NULL);
	result = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (result == NULL)
		return (NULL);
	i = -1;
	r = -1;
	while (s1[++i])
		result[++r] = s1[i];
	i = -1;
	while (s2[++i])
		result[++r] = s2[i];
	result[r + 1] = '\0';
	return (result);
}
