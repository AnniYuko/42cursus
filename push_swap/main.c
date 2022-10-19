/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:40:19 by akroll            #+#    #+#             */
/*   Updated: 2022/10/19 17:08:44 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_int_stacks	stacks;

	(void)argv;

	if (!init(&stacks, argc))
		return (1);
	// if (input_to_stack(&stacks, argc, argv) == 1)
	// 	ft_error(1);
	// sorting(&stacks);

	// #ifdef DEBUG
	// print_list(*(stacks.a), *(stacks.b));
	// #endif

	return (0);
}
