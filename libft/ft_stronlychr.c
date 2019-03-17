/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stronlychr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:40:41 by amakaren          #+#    #+#             */
/*   Updated: 2018/12/07 17:40:52 by amakaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_stronlychr(char const *s, char c)
{
	int		result;
	int		i;

	result = 1;
	i = -1;
	while (s[++i])
		if (s[i] != c)
			result = 0;
	return (result);
}
