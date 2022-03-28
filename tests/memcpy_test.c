/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:45:52 by akroll            #+#    #+#             */
/*   Updated: 2022/03/28 11:23:44 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int main()
{
	char str[] = "happy birthday";
	char *p;

	printf("before: %s\n", str);

	p = ft_memcpy(str, str + 6, 5);
	printf("after memcpy: %s\n", p);
	return 0;
}
