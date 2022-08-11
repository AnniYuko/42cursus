/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:42:25 by akroll            #+#    #+#             */
/*   Updated: 2022/08/11 14:14:21 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define BASE 10

int	print_array(int *arr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		printf("element %u: %d\n", i, arr[i]);
		i++;
	}
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

void	bzero_arr(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
}

int	*radix_sort(int *input_arr, unsigned int size, unsigned int digits)
{
	int				*output_arr;
	unsigned int	count_arr[BASE-1];
	unsigned int	i;
	unsigned int	mod;
	unsigned int	num;

	mod = 1;
	output_arr = calloc(size, sizeof(int));
	while (digits > 0)
	{
		// counting_sort
		bzero_arr(count_arr, BASE);
		i = 0;
		while (i < size)
		{
			num = input_arr[i] / mod % 10;
			count_arr[num] += 1;
			i++;
		}
		mod *= 10;
		digits--;
		printf("---- counting sort \n");
		print_array(count_arr, BASE);

		// prefix sum
		i = 1;
		while (i < BASE)
		{
			count_arr[i] += count_arr[i - 1];
			i++;
		}
		printf("---- prefix sum\n");
		print_array(count_arr, BASE);
	}
	return (output_arr);
}

int	main()
{
	int	n;
	int	arr[] = { 23, 9, 52, 90, 1 };
	int	*sorted_arr;
	int	digits;
	int	max;

	n = sizeof(arr)/sizeof(arr[0]);
	max = get_max_num(arr, n);
	digits = get_digits(max);
	sorted_arr = radix_sort(arr, n, digits);

	printf("biggest number: %d\n", max);
	printf("digits: %d\n\n", digits);
	printf("------- input -----------\n");
	print_array(arr, n);
	printf("------- output -----------\n");
	print_array(sorted_arr, n);
}
