/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:40:19 by akroll            #+#    #+#             */
/*   Updated: 2022/09/23 14:57:29 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #define DEBUG

t_stack	*ft_stack_new(int num)
{
	t_stack	*elem;

	elem = malloc(sizeof(t_stack));
	if (!elem)
		return (NULL);
	elem->num = num;
	elem->next = NULL;
	return (elem);
}

t_stack **stack_add_front(t_stack **top, t_stack *new)
{
	if (*top == NULL)
		*top = new;
	else
	{
		new->next = *top;
		*top = new;
	}
	return (top);
}

int main(int argc, char *argv[])
{
	t_stack **top_of_stack;
	t_stack *tmp;
	t_stack	*new;
	char	**num_arr;
	int	i;

	new = NULL;
	top_of_stack = malloc(sizeof(t_stack*));
	if (!top_of_stack)
		return (1);
	if (argc == 2)
	{
		num_arr = ft_split(argv[1], ',');
		i = 0;
		while (num_arr[i] != NULL)
		{
			new = ft_stack_new(ft_atoi(num_arr[i]));
			// if new == NULL, free the entire list and return
			top_of_stack = stack_add_front(top_of_stack, new);
			#ifdef DEBUG
			printf("at the top: %p, content: %d\n", *top_of_stack, (**top_of_stack).num);
			printf("elem %p\n\tcontent: %d\n\tnext: %p\n\n", new, new->num, new->next);
			#endif
			i++;
		}
		free(num_arr);
	}
	else
	{
		write(1, "Please enter a list of numbers\n", 31);
		return (1);
	}

	// print out
	write(1, "What the stack looks like:\n", 27);
	tmp = *top_of_stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->num);
		tmp = tmp->next;
	}
}
