/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:40:19 by akroll            #+#    #+#             */
/*   Updated: 2022/09/26 15:03:24 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #define DEBUG

int main(int argc, char *argv[])
{
	t_list	**stack_a;
	t_list	**stack_b;
	t_list	*new;
	char	**char_arr;
	long	*num_arr;
	int		size;
	int		i;

	if (argc >= 2)
	{
		stack_a = malloc(sizeof(t_list*)); // free in the end
		stack_b = malloc(sizeof(t_list*)); // free in the end
		if (!stack_a || !stack_b)
			return (1);
		char_arr = ft_split(argv[1], ' ');
		size = arr_get_size(char_arr);
		num_arr = convert_to_int(char_arr, size);
		// free char_arr
		i = 0;
		while (i < size)
		{
			new = ft_lstnew(&num_arr[i]);
			// if new == NULL, free the entire list and return
			ft_lstadd_back(stack_a, new);
			i++;
		}
	}
	else
	{
		write(1, "Please enter a list of numbers\n", 31);
		return (1);
	}
	print_list(*stack_a, *stack_b);

	list_sa(stack_a);
	print_list(*stack_a, *stack_b);

	list_pa(stack_a, stack_b);
	print_list(*stack_a, *stack_b);

	list_ra(stack_a);
	print_list(*stack_a, *stack_b);

	list_rra(stack_a);
	print_list(*stack_a, *stack_b);

	list_rrb(stack_b);
	print_list(*stack_a, *stack_b);
}
