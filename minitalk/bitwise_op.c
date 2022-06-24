/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:35:42 by akroll            #+#    #+#             */
/*   Updated: 2022/06/24 11:36:30 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	show_bits(unsigned int num)
{
	int				position_i;
	unsigned long	lu;

	position_i = sizeof(int) * 8 - 1;
	lu = 1;
	while (position_i >= 0)
	{
		putchar(num & (lu << position_i) ? '1' : '0');
		position_i--;
	}
	putchar('\n');
}

int main()
{
	// printf("unsigned int: %lu\n", sizeof(unsigned int));
	// printf("unsigned char: %lu\n", sizeof(unsigned char));
	// printf("unsigned: %lu\n", sizeof(unsigned));
	// printf("int: %lu\n", sizeof(int));

	int j = 5225;
	printf("%d in binary \t ", j);
	show_bits(j);

	int result = j >> 1;
	printf("%d >> 1 = %d ", j, result);
	show_bits(result);

	return 0;
}
