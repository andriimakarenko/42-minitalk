/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 14:36:34 by amakaren          #+#    #+#             */
/*   Updated: 2019/03/17 22:05:14 by pkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <sys/types.h>
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct		s_message
{
	char			*text;
	char			gchar;
	unsigned char	gbit;
}					t_message;

/*
** The server functions
*/

// void		print_message(char *str);
char				*add_char(char *str, char c);
void				get_new_message(void);
static void			handle_sig1(int sig);
static void			handle_sig2(int sig);

#endif
