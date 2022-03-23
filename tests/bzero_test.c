/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 09:57:45 by akroll            #+#    #+#             */
/*   Updated: 2022/03/23 09:59:34 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../ft_bzero.c"

int main()
{
	char str1[] = "tree";
	char str2[] = "arbol";

	ft_bzero(str1, 10);

	printf("%s", str1);
	printf("%s", str2);

	return 0;
}
