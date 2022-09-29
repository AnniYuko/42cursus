/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:40:19 by akroll            #+#    #+#             */
/*   Updated: 2022/09/28 16:38:50 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_two_stacks	stacks;

	if (argc < 2 || init(&stacks) == 1)
		ft_error();
	if (input_to_stack(&stacks, argc, argv) == 1)
		ft_error();
	sorting(&stacks);

	#ifdef DEBUG
	print_list(*(stacks.a), *(stacks.b));
	#endif

	// clean();
	return (0);
}
