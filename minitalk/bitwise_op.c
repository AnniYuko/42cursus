/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 13:35:42 by akroll            #+#    #+#             */
/*   Updated: 2022/06/27 13:40:23 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

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

unsigned char	reverse_byte(unsigned char original)
{
	unsigned int	i;
	unsigned char	reversed;

	i = 0;
	reversed = 0;
	while (i < 8)
	{
		reversed |= ((original >> i) & 1) << (7 - i);
		i++;
	}
	return (reversed);
}

int main()
{
	// show the bits
	int j = 5225;
	printf("%d in binary \t", j);
	show_bits(j, 2);

	// show right shift, examples
	int result = j >> 1;
	printf("%d >> 1 \t", j);
	show_bits(result, 2);
	result = j >> 2;
	printf("%d >> 2 \t", j);
	show_bits(result, 2);

	// reverse byte
	printf("\n ----reverse byte-------\n");
	unsigned char c = 5;
	printf("5 in binary \t");
	show_bits(c, 1);
	printf("reversed \t");
	show_bits(reverse_byte(c), 1);
	return 0;
}
