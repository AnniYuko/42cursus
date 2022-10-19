/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:49:24 by akroll            #+#    #+#             */
/*   Updated: 2022/10/19 17:09:28 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
// # include <stdio.h>
// # include <stdlib.h>
// # include <unistd.h>
# include <stdbool.h>
// # include <limits.h>

// # define DEBUG

typedef struct s_int_stacks {
	int	*a;
	int	*b;
	int	size;
} t_int_stacks;

// init.c
bool	init(t_int_stacks *stacks, int argc);
// error.c
void	ft_error(int clean);
// sorting.c

#endif
