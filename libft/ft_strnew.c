/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 21:21:18 by amakaren          #+#    #+#             */
/*   Updated: 2018/12/05 22:42:05 by amakaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	int		i;
	char	*fresh;

	fresh = (char*)malloc(size + 1);
	if (fresh == NULL)
		return (NULL);
	i = -1;
	while (++i < (int)size)
		fresh[i] = '\0';
	fresh[size] = '\0';
	return (fresh);
}
