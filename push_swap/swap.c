/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:28:52 by akroll            #+#    #+#             */
/*   Updated: 2022/09/26 14:31:54 by akroll           ###   ########.fr       */
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

void	list_sa(t_list **stack_a)
{
	*stack_a = ft_lst_swap(*stack_a);
	if (*stack_a)
		write(1, "sa\n", 3);
	else
		ft_error();
	// error or return value?
}

void	list_sb(t_list **stack_b)
{
	*stack_b = ft_lst_swap(*stack_b);
	if (*stack_b)
		write(1, "sb\n", 3);
	else
		ft_error();
	// else error or return value?
}

void	list_ss(t_list **stack_a, t_list **stack_b)
{
	list_sa(stack_a);
	list_sb(stack_b);
}
