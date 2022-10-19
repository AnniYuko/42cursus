/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:52:20 by akroll            #+#    #+#             */
/*   Updated: 2022/10/19 17:10:48 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*convert_to_int(char **char_arr, int size)
{
	int	*num_arr;
	int		i;

	i = 0;
	num_arr = malloc(size * sizeof(int));
	if (!num_arr)
		return(NULL);
	while (i < size)
	{
		num_arr[i] = ft_atoi(char_arr[i]);
		i++;
	}
	return (num_arr);
}

int	arr_get_size(char **char_arr)
{
	int i;

	i = 0;
	while (char_arr[i] != NULL)
		i++;
	return (i);
}
