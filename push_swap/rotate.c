/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:37:48 by akroll            #+#    #+#             */
/*   Updated: 2022/09/26 14:46:56 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shift up all elements, first elem becomes last
t_list	*ft_lst_rotate(t_list *top)
{
	t_list	*new_top;

	if (!top)
		return (NULL);
	ft_lstlast(top)->next = top;
	new_top = top->next;
	top->next = NULL;
	return (new_top);
}

void	list_ra(t_list **stack_a)
{
	*stack_a = ft_lst_rotate(*stack_a);
	if (*stack_a)
		write(1, "ra\n", 3);
	else
		ft_error();
	// error or return value?
}

void	list_rb(t_list **stack_b)
{
	*stack_b = ft_lst_rotate(*stack_b);
	if (*stack_b)
		write(1, "rb\n", 3);
	else
		ft_error();
	// else error or return value?
}

void	list_rr(t_list **stack_a, t_list **stack_b)
{
	list_ra(stack_a);
	list_rb(stack_b);
}
