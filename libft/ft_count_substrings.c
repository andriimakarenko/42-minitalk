/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_substrings.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:35:54 by amakaren          #+#    #+#             */
/*   Updated: 2018/12/05 22:21:24 by amakaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_substrings(char const *s, char c)
{
	int i;
	int result;

	i = 0;
	if (!s[i])
		return (0);
	result = 0;
	while (s[i++])
		if (s[i] != '\0' && s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			result++;
	return (result);
}
