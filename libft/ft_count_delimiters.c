/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_delimiters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:58:12 by amakaren          #+#    #+#             */
/*   Updated: 2018/12/05 22:19:47 by amakaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_delimiters(const char *str, char c)
{
	int i;
	int result;

	result = 0;
	i = 0;
	while (str[i++])
		if (str[i] != c)
			break ;
	while (str[i++])
		if (str[i] == c && str[i + 1] && str[i + 1] != c)
			result++;
	return (result);
}
