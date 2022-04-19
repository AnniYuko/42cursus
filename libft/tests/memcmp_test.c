/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:04:11 by akroll            #+#    #+#             */
/*   Updated: 2022/04/19 17:33:03 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../libft.h"

int main()
{
	int return_val;

	return_val = ft_memcmp("1", "\0", 0);

	if ( return_val > 0)
		printf("s1 is bigger than s2\n");
	else if (return_val < 0)
		printf("s2 is bigger than s1\n");
	else
		printf("identical\n");

	return 0;
}
