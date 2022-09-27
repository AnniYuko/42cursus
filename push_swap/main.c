/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:40:19 by akroll            #+#    #+#             */
/*   Updated: 2022/09/27 14:21:31 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#define DEBUG

int	init(t_two_stacks *stacks, int argc, char *argv[])
{
	stacks->a = malloc(sizeof(t_list*));
	stacks->b = malloc(sizeof(t_list*));

	if (!stacks->a || !stacks->b)
		return (1);

	(void)argc;
	(void)argv;
	return (0);
}

int main(int argc, char *argv[])
{
	t_two_stacks	stacks;
	t_list			*new;
	char			**char_arr;
	int				*num_arr;
	int				size;
	int				i;
	int				count;

	if (argc >= 2)
	{
		if (init(&stacks, argc, argv) == 1)
			return (1);
		count = 1;
		while (count < argc)
		{
			char_arr = ft_split(argv[count], ' ');
			size = arr_get_size(char_arr);
			num_arr = convert_to_int(char_arr, size);
			// free char_arr
			i = 0;
			while (i < size)
			{
				new = ft_lstnew(&num_arr[i]);
				// if new == NULL, free the entire list and return
				ft_lstadd_back(stacks.a, new);
				i++;
			}
			count++;
		}
	}
	else
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
