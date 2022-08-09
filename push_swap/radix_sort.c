/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:42:25 by akroll            #+#    #+#             */
/*   Updated: 2022/08/05 11:39:38 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	print_array(int *arr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		printf("element %u: %d\n", i, arr[i]);
		i++;
	}
	printf("---------------------\n");
	return (0);
}


int	get_max_num(int *arr, int size)
{
	int	i;
	int	max;

	max = arr[0];
	i = 1;
	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

int	get_digits(int num)
{
	int	count;

	count = 0;
	while (num > 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

int	*radix_sort(int *arr, unsigned int size, unsigned int digits)
{
	int	*sorted_arr;

	sorted_arr = calloc(size, sizeof(int));
	(void)digits;
	// while ()
		// counting_sort();
	return (sorted_arr);
}

int	main()
{
	int	n;
	int	arr[] = { 23, 9, 52, 467, 22, 142, 90, 1 };
	int	*sorted_arr;
	int	digits;
	int	max;

	n = sizeof(arr)/sizeof(arr[0]);
	max = get_max_num(arr, n);
	digits = get_digits(max);
	sorted_arr = radix_sort(arr, n, digits);

	printf("biggest number: %d\n", max);
	printf("digits: %d\n\n", digits);
	print_array(arr, n);
	print_array(sorted_arr, n);
}
