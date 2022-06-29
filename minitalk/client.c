/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:28:26 by akroll            #+#    #+#             */
/*   Updated: 2022/06/29 14:01:40 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
// for atoi():
#include <stdlib.h>

void	show_bits(unsigned int num, int num_of_bytes)
{
	int				position_i;
	unsigned long	lu;

	position_i = 8 * num_of_bytes - 1;
	lu = 1;
	while (position_i >= 0)
	{
		putchar(num & (lu << position_i) ? '1' : '0');
		if (!(position_i % 8))
			putchar(' ');
		position_i--;
	}
	putchar('\n');
}

void	send_str_as_signals(pid_t pid, char *str)
{
	int	i;
	int	position;

	i = 0;
	while (str[i] != '\0')
	{
		position = 7;
		while (position >= 0)
		{
			if ((str[i] >> position) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(10);
			position--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;

	if (argc != 3)
	{
		write(1, "Please enter 3 arguments:\n./client <server_pid> \"string\"\n", 58);
		return (1);
	}
	server_pid = atoi(argv[1]);
	send_str_as_signals(server_pid, argv[2]);

	return (0);
}
