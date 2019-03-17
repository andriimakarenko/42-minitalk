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

t_message g_message;

void	print_message(char *str)
{
	ft_putstr("The message is received:\n");
	ft_putstr(str);
	ft_putchar('\n');
}

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

t_message	*get_new_message(void)
{
	t_message	*result;

	// result = (t_message*)malloc(sizeof(t_message));
	// result.text
	// message[0] = '\0';
	result = NULL;
	return (result);
}

void	*update_char(int sig)
{
		int value;

		value = 0;
		if (sig == SIGUSR1)
			value = 1;
		g_message.gchar ^= (-value ^ g_message.gchar) & (1UL << g_message.gbit);
		g_message.gbit++;
		return (NULL);
}

int		main(void)
{
	int		proc_id;

	proc_id = (int)getpid();
	ft_putstr(ft_strjoin(ft_itoa(proc_id), \
	" - my PID. If you enter anything other than exactly this, I won't work, \
	and that's a designed feature, not a bug.\n\n"));
	signal(SIGUSR1, update_char(SIGUSR1));
	signal(SIGUSR2, update_char(SIGUSR2));
	g_message = *(get_new_message());
	while (ft_strcmp(g_message.text, "exit"))
	{
		if (g_message.gbit == 8)
		{
			g_message.text = add_char(g_message.text, g_message.gchar);
			g_message.gbit = 0;
			if (g_message.gchar == '\0')
				print_message(g_message.text);
		}
		usleep(3);
	}
	return (0);
}
