/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:18:11 by amakaren          #+#    #+#             */
/*   Updated: 2018/12/06 20:18:16 by amakaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*result;
	t_list	*step;

	if (!(lst) || !(f))
		return (NULL);
	if (!(result = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	result = f(lst);
	step = result;
	while (lst->next)
	{
		lst = lst->next;
		if (!(step->next = f(lst)))
			return (NULL);
		step = step->next;
	}
	return (result);
}
