/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:17:05 by akroll            #+#    #+#             */
/*   Updated: 2022/09/25 17:53:54 by akroll           ###   ########.fr       */
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
	top->next = second->next;
	second->next = top;

	return (second);
}

// push first element from one list/stack to the top of the other
void	ft_lst_push(t_list **top_from, t_list **top_to)
{
	t_list	*second_from;
	t_list	*first_to;

	if (*top_from == NULL)
		return;
	second_from = (*top_from)->next;
	first_to = *top_to;
	ft_lstadd_front(top_to, *top_from);
	(*top_to)->next = first_to;
	*top_from = second_from;
}

// Shift up all elements, first elem becomes last
t_list	*ft_lst_rotate(t_list *top)
{
	t_list	*new_top;

	if (!top)
		return (top);
	ft_lstlast(top)->next = top;
	new_top = top->next;
	top->next = NULL;
	return (new_top);
}

// shift down all elements, last elem becomes first
t_list	*ft_lst_reverse_rotate(t_list *top)
{
	t_list	*penultimate;

	if (!top || !top->next)
		return (top);
	penultimate = ft_lstpenultimate(top);
	penultimate->next->next = top;
	top = penultimate->next;
	penultimate->next = NULL;
	return (top);
}
