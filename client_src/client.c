/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 21:49:24 by pkuznets          #+#    #+#             */
/*   Updated: 2019/03/17 21:50:57 by pkuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int		is_numeric(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

void	send_symbol(int server_pid, unsigned char sym)
{
	uint8_t		i;

	i = 1 << 7;
	while (i)
	{
		if (sym & i)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				ft_putstr("Fail.\n");
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				ft_putstr("Fail.\n");
		}
		i >>= 1;
		usleep(300);
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
	int	i;

	if (argc != 3 || !(argv[1]))
		return (ft_putstr_mod("Usage: \"./client_src server_PID message\"\n"));
	if (!argv[2] || !argv[2][0])
		return (ft_putstr_mod("Stop messin with me, \
		enter a valid message\n"));
	if (is_numeric(argv[1]) != 0)
		return (ft_putstr_mod("PID must comprise of numbers only\n"));
	server_pid = (pid_t)ft_atoi(argv[1]);
	sender(server_pid, argv[2]);
	if (server_pid < 0)
		return (ft_putstr_mod("PID should be between 0 and int max\n"));
}
