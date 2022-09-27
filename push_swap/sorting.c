/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:19:28 by akroll            #+#    #+#             */
/*   Updated: 2022/09/27 14:00:00 by akroll           ###   ########.fr       */
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
			ft_error();
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
	if (get_value(first) > get_value(first->next))
		list_sa(stack_a);
}
