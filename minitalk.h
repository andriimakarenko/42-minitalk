/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 14:36:34 by amakaren          #+#    #+#             */
/*   Updated: 2019/03/17 14:37:57 by amakaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

#include "libft/libft.h"
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

/*
** The server functions
*/

void	print_message(char **str);
char	*add_char(char *str, char c, int);
char	*get_new_message(void);
void	update_buffer(char *buf, short value, short *sig_counter);

#endif