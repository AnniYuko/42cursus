/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:41:12 by akroll            #+#    #+#             */
/*   Updated: 2022/10/19 17:11:18 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// bool	is_int(char **arr)
// {
// 	int		i;
// 	long	num;

// 	i = 0;
// 	num = 0;
// 	while (arr[i])
// 	{
// 		num = ft_atol(arr[i]);
// 		if (num < INT_MIN || num > INT_MAX)
// 			return (false);
// 		i++;
// 	}
// 	return (true);
// }

bool	init(t_int_stacks *stacks, int argc)
{
	if (argc < 2)
		return (false);
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->size = 0;
	return (true);
}

// int	input_to_stack(t_two_stacks *stacks, int argc, char *argv[])
// {
// 	char	**char_arr;
// 	// char	*input_str;
// 	int		i;

// 	// input_str = join_input_strings(argc, argv);
// 	char_arr = ft_split(argv[0], ' ');
// 	stacks->size = arr_get_size(char_arr);
// 	if (!is_int(char_arr))
// 		return (1); // + output Error
// 	stacks->num_arr = convert_to_int(char_arr, stacks->size);
// 	// free char_arr
// 	i = 0;
// 	while (i < stacks->size)
// 	{

// 	}
// 	return (0);
// }
