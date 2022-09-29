/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:19:28 by akroll            #+#    #+#             */
/*   Updated: 2022/09/29 15:43:56 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting(t_two_stacks *stacks)
{
	while  (!is_sorted(stacks->a))
	{
		#ifdef DEBUG
		print_list(*(stacks->a), *(stacks->b));
		#endif

		sort_small_stack(stacks->a);
	}
}

int	get_value(t_list *elem)
{
	return (*(int*)(elem->content));
}

bool	is_sorted(t_list **stack)
{
	t_list	*elem;

	elem = *stack;
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
	int	first;
	int	second;
	// int	third;

	first = get_value(*stack_a);
	second = get_value((*stack_a)->next);
	if (first > second)
		list_sa(stack_a);
	// third = get_value((*stack_a)->next->next);
	// if (first > second && second < third && third > first)
		// list_sa(stack_a);
	// if (first > second)
}
