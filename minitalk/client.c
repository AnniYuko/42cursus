/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 09:28:26 by akroll            #+#    #+#             */
/*   Updated: 2022/06/28 14:25:18 by akroll           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*str;
	int		i;
	int		j;

	if (argc != 3)
	{
		write(1, "Please enter 3 arguments:\n./client <server_pid> <string>\n", 58);
		return (1);
	}
	str = argv[2];
	server_pid = atoi(argv[1]);

	i = 0;
	while (str[i] != '\0')
	{
		show_bits(str[i], 1);
		j = 7;
		while (j >= 0)
		{
			if ((str[i] >> j) & 1)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(10);
			j--;
		}
		i++;
	}

	return (0);
}
