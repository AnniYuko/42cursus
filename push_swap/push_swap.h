/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:49:24 by akroll            #+#    #+#             */
/*   Updated: 2022/09/24 17:14:42 by akroll           ###   ########.fr       */
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

// functions
long	*convert_to_int(char **char_arr, int size);
void	print_list(t_list *stack_a, t_list *stack_b);
int		arr_get_size(char **char_arr);
// stack operations
t_list	*ft_lst_swap(t_list *top);
t_list	*ft_lst_rotate(t_list *top);
t_list	*ft_lst_reverse_rotate(t_list *top);

#endif
