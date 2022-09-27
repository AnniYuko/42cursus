/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:40:19 by akroll            #+#    #+#             */
/*   Updated: 2022/09/27 16:40:55 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define DEBUG

int main(int argc, char *argv[])
{
	t_two_stacks	stacks;

	if (argc < 2 || init(&stacks) == 1)
		return (1);
	if (input_to_stack(&stacks, argc, argv) == 1)
		return (1);

	while  (!is_sorted(stacks.a))
	{
		#ifdef DEBUG
		print_list(*(stacks.a), *(stacks.b));
		#endif

		sort_small_stack(stacks.a);
	}

	#ifdef DEBUG
	print_list(*(stacks.a), *(stacks.b));
	write(1, "is sorted!\n", 11);
	#endif
}
