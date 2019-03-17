/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amakaren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 01:24:39 by amakaren          #+#    #+#             */
/*   Updated: 2019/03/16 01:24:39 by amakaren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int is_numeric(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return(0);
}

int		*c_to_bin(char msg)
{
	int 	i;
	int		k;
	int		*buf;

	i = 8;
	k = 0;
	buf = ft_memalloc(8);
	while (i-- > 0)
	{
		buf[k] = msg >> i;
		buf[k] = buf[k] % 2;
		k++;
	}
	return (buf);
}

void	send_symbol(pid_t server_pid, char c)
{
	int			i;
	int			*buf;

	i = 0;
	buf = c_to_bin(c);
	while (i < 8)
	{
		if (buf[i] == 0)
		{
			ft_putnbr(0);
			if (kill(server_pid, SIGUSR1) == -1)
				exit(0);
		}
		else
		{
			ft_putnbr(1);
			if (kill(server_pid, SIGUSR2) == -1)
				exit(0);
		}
		ft_putchar('\n');
		i++;
		free (buf);
	}
}

void	sender(int server_pid, const char *message)
{
	int i;

	i = 0;
	while (message[i] != '\0')
	{
		send_symbol(server_pid, message[i]);
		i++;
	}
	send_symbol(server_pid, '\0');
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	int i;

	if (argc != 3 || !(argv[1]))
		return (ft_putstr_mod("Usage: \"./client server_PID message\"\n"));
	if (!argv[2] || !argv[2][0])
		return (ft_putstr_mod("Stop messin with me, \
				enter a valid message\n"));
	if (is_numeric(argv[1]) != 0)
		return (ft_putstr_mod("PID must comprise of numbers only\n"));
	server_pid = (pid_t)ft_atoi(argv[1]);
	sender(server_pid, argv[2]);
	if (server_pid < 0)
		return (ft_putstr_mod("PID should be between 0 and int max\n"));
	signal(SIGUSR1, (void *)(ft_putstr_mod("The server confirmed receival\n")));
}
