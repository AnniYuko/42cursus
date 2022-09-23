/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:45:52 by akroll            #+#    #+#             */
/*   Updated: 2022/04/19 17:33:08 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int main()
{
	char const *src = "happy birthday";
	int nums[6] = {1, 5, -3, 18, 128, -994};
	char dest[16];
	int dest_nums[6] = {0};
	unsigned int i;
	unsigned int n;

	i = 0;
	n = sizeof(dest_nums)/sizeof(int);
	ft_memcpy(dest_nums, nums, 8);
	printf("copied numbers:\n");
	while (i++ < n)
	{
		printf("%d\n", dest_nums[i]);
	}

	ft_memcpy(dest, src, ft_strlen(src));
	printf("copied string: %s\n", dest);
	return 0;
}
