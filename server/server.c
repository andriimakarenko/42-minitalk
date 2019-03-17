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

void	print_message(char **str)
{
	ft_putstr("The message is received:\n");
	ft_putstr(*str);
	ft_putchar('\n');
	*str = get_new_message();
}

char	*add_char(char *str, char c, int)
{
	char	*result;
	int		i;

	result = (char*)malloc(sizeof(char) * ft_strlen(str) + 2);
	i = -1;
	while (str[++i])
		result[i] = str[i];
	result[i] = c;
	result[i + 1] = '\0';
}

char	*get_new_message(void)
{
	char	*result;

	result = (char*)malloc(sizeof(char));
	message[0] = '\0';
	return (result);
}

void	update_buffer(char *buf, short value, short *sig_counter)
{
		*buf ^= (-value ^ *buf) & (1UL << *sig_counter);
		*sig_counter++
}

int		main(int argc, char **argv)
{
	int		proc_id;
	char	buf;
	char	*message;
	short	sig_counter;

	proc_id = (int)getpid();
	ft_putstr(ft_strjoin(ft_itoa(proc_id), \
	" - my PID. If you enter anything other than exactly this, I won't work, \
	and that's a designed feature, not a bug.\n\n"));
	signal(SIGUSR1, update_buffer(&(buf), 1, sig_counter));
	signal(SIGUSR2, update_buffer(&(buf), 0, sig_counter));
	message = get_new_message();
	sig_counter = 0;
	while (message != "exit")
	{
		if (sig_counter == 8)
		{
			message = add_char(message, buf);
			sig_counter = 0;
			i++;
			if (buf == '\0')
				print_message(&(message));
		}
		usleep(3);
	}
	return (0);
}
