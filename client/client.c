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
	__builtin_printf(str);
	return (0);
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
		return (print_exit("Usage: \"./client server_PID message\"\n"));
	if (!argv[2] || !argv[2][0])
		return (print_exit("Stop messin with me, \
				enter a valid message\n"));
	if (!(isnumeric(argv[1])))
		return (print_exit("PID must comprise of numbers only\n"));
	server_pid = (pid_t);
	if (server_pid < 0)
		return (print_exit("PID should be between 0 and int max\n"));
}
