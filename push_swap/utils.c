/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:52:20 by akroll            #+#    #+#             */
/*   Updated: 2022/09/24 17:20:01 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*convert_to_int(char **char_arr, int size)
{
	long	*num_arr;
	int		i;

	i = 0;
	num_arr = malloc(size * sizeof(long));
	if (!num_arr)
		return(NULL);
	while (i < size)
	{
		num_arr[i] = ft_atoi(char_arr[i]);
		i++;
	}
	return (num_arr);
}

void	print_list(t_list *stack_a, t_list *stack_b)
{
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			printf("\t%li", *(long*)(stack_a->content));
			stack_a = stack_a->next;

		}
		if (stack_b)
		{
			printf("\t%li", *(long*)(stack_b->content));
			stack_b = stack_b->next;
		}
		printf("\n");
	}
	printf("\t__\t__\n");
	printf("\t a\t b\n");
}

int	arr_get_size(char **char_arr)
{
	int i;

	i = 0;
	while (char_arr[i] != NULL)
		i++;
	return (i);
}