/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 14:30:19 by akroll            #+#    #+#             */
/*   Updated: 2022/09/26 14:37:14 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// push first element from one list/stack to the top of the other
int	ft_lst_push(t_list **top_from, t_list **top_to)
{
	t_list	*second_from;

	if (*top_from == NULL)
		return (1);
	second_from = (*top_from)->next;
	ft_lstadd_front(top_to, *top_from);
	*top_from = second_from;
	return (0);
}

void	list_pa(t_list **stack_a, t_list **stack_b)
{
	if (ft_lst_push(stack_a, stack_b) == 0)
		write(1, "pa\n", 3);
	else
		ft_error();
	// error or return value?
}

void	list_pb(t_list **stack_a, t_list **stack_b)
{
	if (ft_lst_push(stack_b, stack_a) == 0)
		write(1, "pb\n", 3);
	else
		ft_error();
	// error or return value?
}
