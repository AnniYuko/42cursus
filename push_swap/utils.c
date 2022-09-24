/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:52:20 by akroll            #+#    #+#             */
/*   Updated: 2022/09/24 15:24:47 by akroll           ###   ########.fr       */
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

void	print_list(t_list **top_of_stack)
{
	t_list *tmp;

	write(1, "What the stack looks like:\n", 27);
	tmp = *top_of_stack;
	while (tmp != NULL)
	{
		printf("\t%li\n", *(long*)(tmp->content));
		tmp = tmp->next;
	}
}

int	arr_get_size(char **char_arr)
{
	int i;

	i = 0;
	while (char_arr[i] != NULL)
		i++;
	return (i);
}
