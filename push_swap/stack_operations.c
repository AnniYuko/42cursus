/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 13:17:05 by akroll            #+#    #+#             */
/*   Updated: 2022/09/24 16:53:43 by akroll           ###   ########.fr       */
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

// void	ft_lst_push(t_list *top_a, t_list *top_b)
// {

// }

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
