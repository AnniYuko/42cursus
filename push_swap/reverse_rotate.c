/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:37:48 by akroll            #+#    #+#             */
/*   Updated: 2022/09/26 14:58:40 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// shift down all elements, last elem becomes first
t_list	*ft_lst_reverse_rotate(t_list *top)
{
	t_list	*penultimate;

	if (!top || !top->next)
		return (NULL);
	penultimate = ft_lstpenultimate(top);
	penultimate->next->next = top;
	top = penultimate->next;
	penultimate->next = NULL;
	return (top);
}

void	list_rra(t_list **stack_a)
{
	*stack_a = ft_lst_reverse_rotate(*stack_a);
	if (*stack_a)
		write(1, "rra\n", 3);
	else
		ft_error();
	// error or return value?
}

void	list_rrb(t_list **stack_b)
{
	*stack_b = ft_lst_reverse_rotate(*stack_b);
	if (*stack_b)
		write(1, "rrb\n", 3);
	else
		ft_error();
	// else error or return value?
}

void	list_rrr(t_list **stack_a, t_list **stack_b)
{
	list_rra(stack_a);
	list_rrb(stack_b);
}
