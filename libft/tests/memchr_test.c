/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:00:36 by akroll            #+#    #+#             */
/*   Updated: 2022/04/19 17:32:59 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int main()
{
	char str[] = "happy birthday";
	char *p;

	p = ft_memchr(str, 'y', sizeof(str));
	printf("found at position %ld\n", (p - str + 1));
	printf("character: %c\n", *p);
	return 0;
}
