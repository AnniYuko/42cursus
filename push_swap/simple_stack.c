/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:40:19 by akroll            #+#    #+#             */
/*   Updated: 2022/09/22 16:52:30 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int num)
{
	t_stack	*elem;

	elem = malloc(sizeof(t_stack));
	elem->num = num;
	elem->next = NULL;
	return (elem);
}

int main(void)
{
	t_stack **top;
	t_stack *tmp;
	t_stack *elem1;
	t_stack *elem2;

	elem1 = ft_lstnew(2);
	elem2 = ft_lstnew(4);

	*top = elem1;
	elem1->next = elem2;

	tmp = *top;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->num);
		tmp = tmp->next;
	}
}
