/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:18:11 by amakaren          #+#    #+#             */
/*   Updated: 2018/12/06 20:18:13 by amakaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*targetlist;
	t_list	*nextlist;

	if (!(*alst) || !(del))
		return ;
	targetlist = *alst;
	while (targetlist)
	{
		nextlist = targetlist->next;
		del(targetlist->content, targetlist->content_size);
		free(targetlist);
		targetlist = nextlist;
	}
	*alst = NULL;
}
