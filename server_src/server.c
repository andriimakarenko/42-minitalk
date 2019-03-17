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

int		ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char	*ft_itoa_base(int value, int base)
{
	char	*str;
	int		size;
	char	*tab;
	int		flag;
	int		tmp;
	flag = 0;
	size = 0;
	tab = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (0);
	if (value < 0 && base == 10)
		flag = 1;
	tmp = value;
	while (tmp /= base)
		size++;
	size = size + flag + 1;
	str = (char *)malloc(sizeof(char) * size  + 1);
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = tab[ft_abs(value % base)];
		size--;
		value /=base;
	}
	return (str);
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

void	get_new_message(void)
{
	g_message.text = (char*)malloc(sizeof(char));
	g_message.text[0] = '\0';
	g_message.gchar = 0;
	g_message.gbit = 0;
}

// static void	update_char(int sig)
// {
// 		int value;
//
// 		value = 0;
// 		if (sig == SIGUSR1)
// 			value = 1;
// 		if (sig == SIGUSR1)
// 			printf("Received 1\n");
// 		if (sig == SIGUSR2)
// 			printf("Received 2\n");
// 		g_message.gchar ^= (-value ^ g_message.gchar) & (1UL << g_message.gbit);
// 		g_message.gbit++;
// 		printf("Char is now %x\n", g_message.gchar);
// }

static void	handle_sig1(int sig)
{
	(void)sig;
	printf("Read a 1\n");
	g_message.gchar ^= 1 << g_message.gbit;
	printf("Char is now %s\nCurrent bit is %d\n", ft_itoa_base(g_message.gchar, 2), g_message.gbit);
	g_message.gbit++;
}

static void	handle_sig2(int sig)
{
	(void)sig;
	printf("Read a 0\n");
	printf("Char is now %s\nCurrent bit is %d\n", ft_itoa_base(g_message.gchar, 2), g_message.gbit);
	g_message.gbit++;
}

int		main(void)
{
	int		proc_id;

	proc_id = (int)getpid();
	ft_putstr(ft_strjoin(ft_itoa(proc_id), \
	" - my PID. If you enter anything other than exactly this, I won't work,"
	" and that's a designed feature, not a bug.\n\n"));
	// signal(SIGUSR1, update_char);
	// signal(SIGUSR2, update_char);
	signal(SIGUSR1, handle_sig1);
	signal(SIGUSR2, handle_sig2);
	get_new_message();
	while (ft_strcmp(g_message.text, "exit"))
	{
		if (g_message.gbit == 8)
		{
			printf("\nReceived a character \'%c\'\n", g_message.gchar);
			g_message.text = add_char(g_message.text, g_message.gchar);
			printf("The message is now %s\n\n", g_message.text);
			g_message.gbit = 0;
			if (g_message.gchar == '\0')
				ft_putstr(g_message.text);
			get_new_message();
		}
		usleep(30);
	}
	return (0);
}
