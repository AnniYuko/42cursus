/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:41:12 by akroll            #+#    #+#             */
/*   Updated: 2022/09/27 16:55:13 by akroll           ###   ########.fr       */
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

int	init(t_int_stacks *stacks, int size)
{
	if (size <= 0)
		return (1);
	stacks->size = size;
	stacks->a = malloc(sizeof(int) * size);
	stacks->b = malloc(sizeof(int) * size);
	if (!stacks->a || !stacks->b)
		return (1);
	return (0);
}

// int	input_to_stack(t_two_stacks *stacks, int argc, char *argv[])
// {
// 	t_list	*new;
// 	char	**char_arr;
// 	int		i;
// 	int		count;

// 	count = 1;
// 	while (count < argc)
// 	{
// 		char_arr = ft_split(argv[count], ' ');
// 		stacks->size = arr_get_size(char_arr);
// 		if (!is_int(char_arr))
// 			return (1); // + output Error
// 		stacks->num_arr = convert_to_int(char_arr, stacks->size);
// 		// free char_arr
// 		i = 0;
// 		while (i < stacks->size)
// 		{
// 			new = ft_lstnew(&stacks->num_arr[i]);
// 			if (!new)
// 			{
// 				ft_lstclear(stacks->a, free);
// 				return (1);
// 			}
// 			ft_lstadd_back(stacks->a, new);
// 			i++;
// 		}
// 		count++;
// 	}
// 	return (0);
// }
