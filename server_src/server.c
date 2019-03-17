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
#include <stdio.h>
#include <stdlib.h>

t_message g_message;

char	*add_char(char *str, char c)
{
	char	*result;
	int		i;

	result = (char*)malloc(sizeof(char) * ft_strlen(str) + 2);
	i = -1;
	while (str[++i])
		result[i] = str[i];
	result[i] = c;
	result[i + 1] = '\0';
	return (result);
}

void	get_new_message(void)
{
	g_message.text = (char*)malloc(sizeof(char));
	g_message.text[0] = '\0';
	g_message.gchar = 0;
	g_message.gbit = 0;
}

static void	handle_sig1(int sig)
{
	(void)sig;
	g_message.gchar ^= 1 << (7 - g_message.gbit);
	g_message.gbit++;
}

static void	handle_sig2(int sig)
{
	(void)sig;
	g_message.gbit++;
}

int		main(void)
{
	int		proc_id;

	proc_id = (int)getpid();
	ft_putstr(ft_strjoin(ft_itoa(proc_id), " - my PID.\n\n"));
	signal(SIGUSR1, handle_sig1);
	signal(SIGUSR2, handle_sig2);
	get_new_message();
	while (ft_strcmp(g_message.text, "exit"))
	{
		if (g_message.gbit == 8)
		{
			g_message.text = add_char(g_message.text, g_message.gchar);
			g_message.gbit = 0;
			if (g_message.gchar == 0)
			{
				ft_putstr(ft_strjoin("Received:\n", g_message.text));
				ft_putstr("\n");
				get_new_message();
			}
			g_message.gchar = 0;
		}
		usleep(30);
	}
	return (0);
}
