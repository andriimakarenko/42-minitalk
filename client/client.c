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

int	print_exit(char *str)
{
	ft_putstr(str);
	return (0);
}

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

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3 || !(argv[1]))
		return (print_exit("Usage: \"./client server_PID message\"\n"));
	if (!argv[2] || !argv[2][0])
		return (print_exit("Stop messin with me, \
				enter a valid message\n"));
	if (is_numeric(argv[1]) != 0)
		return (print_exit("PID must comprise of numbers only\n"));
	server_pid = (pid_t)ft_atoi(argv[1]);
	if (server_pid < 0)
		return (print_exit("PID should be between 0 and int max\n"));
}
