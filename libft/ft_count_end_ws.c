/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_end_ws.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 22:24:46 by amakaren          #+#    #+#             */
/*   Updated: 2018/12/05 22:20:18 by amakaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_end_ws(char const *s)
{
	int len;
	int res;

	len = -1;
	while (s[++len])
		;
	res = 0;
	while (ft_iswhitespace(s[--len]))
		res++;
	return (res);
}
