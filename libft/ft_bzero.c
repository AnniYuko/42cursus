/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:12:04 by akroll            #+#    #+#             */
/*   Updated: 2022/03/22 16:56:35 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_bzero(void *s, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		//if (s[i] != 0)
		//	s[i] = 0;
		i++;
	}
	return;
}

int main()
{
	void *s;

	ft_bzero(s, 8);
	printf("%s", *(char*)s);
	return 0;
}
