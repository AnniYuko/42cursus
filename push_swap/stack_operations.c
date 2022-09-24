/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:17:05 by akroll            #+#    #+#             */
/*   Updated: 2022/09/24 18:12:15 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// swap the two elements on the top
t_list	*ft_lst_swap(t_list *top)
{
	t_list	*second;

	if (!top || !top->next)
		return (top);

	second = top->next;

	if (!second->next)
		top->next = NULL;
	else
		top->next = second->next;
	second->next = top;

	return (second);
}

// push first element from one list/stack to the top of the other
void	ft_lst_push(t_list **top_from, t_list **top_to)
{
	t_list	*second_from;
	t_list	*first_to;

	second_from = (*top_from)->next;
	if (*top_to)
		first_to = *top_to;
	else
		first_to = NULL;
	ft_lstadd_front(top_to, *top_from);
	(*top_to)->next = first_to;
	*top_from = second_from;
}

// Shift up all elements, first elem becomes last
t_list	*ft_lst_rotate(t_list *top)
{
	t_list	*new_top;

	ft_lstlast(top)->next = top;
	new_top = top->next;
	top->next = NULL;
	return (new_top);
}

// shift down all elements, last elem becomes first
t_list	*ft_lst_reverse_rotate(t_list *top)
{
	t_list	*penultimate;
	t_list	*new_top;

	// !! protect against empty list!!!
	penultimate = top;
	while (penultimate->next->next != NULL)
	{
		penultimate = penultimate->next;
	}
	new_top = penultimate->next;
	new_top->next = top;
	penultimate->next = NULL;
	return (new_top);
}
