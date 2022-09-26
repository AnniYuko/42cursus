/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:19:28 by akroll            #+#    #+#             */
/*   Updated: 2022/09/26 15:49:27 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_value(t_list *elem)
{
	return (*(int*)(elem->content));
}

bool	is_sorted(t_list **stack_a)
{
	t_list	*elem;

	elem = *stack_a;
	while (elem && elem->next)
	{
		if (get_value(elem) > get_value(elem->next))
			return (false);
		if (get_value(elem) == get_value(elem->next))
		{
			write(1, "Duplicate found. Error\n", 23);
			exit (EXIT_FAILURE);
		}
		elem = elem->next;
	}
	return (true);
}

void	sort_small_stack(t_list **stack_a)
{
	t_list	*first;

	first = *stack_a;
	if (*(int*)(first->content) > *(int*)(first->next->content))
		list_sa(stack_a);
}
