/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:45:52 by akroll            #+#    #+#             */
/*   Updated: 2022/03/23 14:51:45 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libft/ft_memcpy.c"

int main()
{
	char str[] = "happy birthday";
	char *p;

	printf("before: %s", str);

	p = ft_memcpy(str, str + 7, 8);
	printf("after memcpy: %s\n", p);
	return 0;
}
