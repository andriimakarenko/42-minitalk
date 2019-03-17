/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 01:22:57 by amakaren          #+#    #+#             */
/*   Updated: 2019/03/16 01:22:57 by amakaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	main(int argc, char **argv)
{
	int		proc_id;
	char	buf[1];
	char	*message;

	proc_id = (int)getpid();
	ft_putstr(ft_strjoin(ft_itoa(proc_id), \
	" - my PID. If you enter anything other than exactly this, I won't work,"
 	" and that's a designed feature, not a bug.\n"));
	return (0);
}
