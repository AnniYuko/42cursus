/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:12:04 by akroll            #+#    #+#             */
/*   Updated: 2022/03/23 09:45:59 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_bzero(void *s, unsigned int n)
{
	char *p;

	p = s;
	while (n-- > 0)
	{
		*p = 0;
		p++;
	}
}

int main()
{
	int i = 0;
	int size = 3;
	char *strs[size];

	strs[0] = "tree";
	strs[1] = "arbol";
	strs[2] = "baum";

	ft_bzero(strs, 1);

	while (i < size)
	{
		printf("%s", strs[i]);
		i++;
	}
	return 0;
}
