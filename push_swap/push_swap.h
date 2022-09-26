/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:49:24 by akroll            #+#    #+#             */
/*   Updated: 2022/09/26 15:01:48 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack {
	int num;
	struct s_stack *next;
} t_stack;

// utils.c
long	*convert_to_int(char **char_arr, int size);
void	print_list(t_list *stack_a, t_list *stack_b);
int		arr_get_size(char **char_arr);
void	ft_error(void);
// swap.c
t_list	*ft_lst_swap(t_list *top);
void	list_sa(t_list **stack_a);
void	list_sb(t_list **stack_b);
void	list_ss(t_list **stack_a, t_list **stack_b);
// push.c
int		ft_lst_push(t_list **top_from, t_list **top_to);
void	list_pa(t_list **stack_a, t_list **stack_b);
void	list_pb(t_list **stack_a, t_list **stack_b);
// rotate.c
t_list	*ft_lst_rotate(t_list *top);
void	list_ra(t_list **stack_a);
void	list_rb(t_list **stack_b);
void	list_rr(t_list **stack_a, t_list **stack_b);
// reverse_rotate.c
t_list	*ft_lst_reverse_rotate(t_list *top);
void	list_rra(t_list **stack_a);
void	list_rrb(t_list **stack_b);
void	list_rrr(t_list **stack_a, t_list **stack_b);

#endif
