/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 13:42:25 by akroll            #+#    #+#             */
/*   Updated: 2022/08/11 17:43:30 by akroll           ###   ########.fr       */
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

void	radix_sort(int *input_arr, int *output_arr, int size, unsigned int digits)
{
	unsigned int	count_arr[BASE];
	unsigned int	i;
	unsigned int	position;
	unsigned int	num;

	position = 1;
	// output_arr = calloc(size, sizeof(int));
	while (digits > 0)
	{
		// counting_sort
		bzero_arr(count_arr, BASE);
		i = 0;
		while (i < size)
		{
			num = input_arr[i] / position % 10;
			count_arr[num] += 1;
			i++;
		}
		// printf("---- counting sort \n");
		// print_array(count_arr, BASE);

		// prefix sum
		i = 1;
		while (i < BASE)
		{
			count_arr[i] += count_arr[i - 1];
			i++;
		}
		// printf("---- prefix sum\n");
		// print_array(count_arr, BASE);

		// radix sort (right to left)
		int index;
		int c = size - 1;
		while (c >= 0)
		{
			num = input_arr[c] / position % 10;
			count_arr[num] -= 1;
			index = count_arr[num];
			output_arr[index] = input_arr[c];
			c--;
		}
		// printf("--- another round of radix sort ---\n");
		// print_array(output_arr, size);

		// ready for next round
		int *tmp;
		if (digits-- > 0)
		{
			tmp = input_arr;
			input_arr = output_arr;
			output_arr = tmp;
		}
		position *= 10;
	}
}

int	main(int argc, char **argv)
{
	int	n;
	int	*arr;
	int	*output_arr;
	int	digits;
	int	max;
	int	*tmp;
	int	i;

	n = argc - 1;
	printf("%d\n", n);
	arr = malloc(n * sizeof(int));
	i = 0;
	while (i < n)
	{
		arr[i] = atoi(argv[i + 1]);
		i++;
	}

	max = get_max_num(arr, n);
	digits = get_digits(max);

	printf("biggest number: %d\n", max);
	printf("digits: %d\n\n", digits);
	printf("------- input -----------\n");
	print_array(arr, n);

	output_arr = malloc(n * sizeof(int));
	radix_sort(arr, output_arr, n, digits);
	if (digits % 2 == 0)
	{
		tmp = arr;
		arr = output_arr;
		output_arr = tmp;
	}

	printf("------- output -----------\n");
	print_array(output_arr, n);
	free(arr);
	free(output_arr);
}
