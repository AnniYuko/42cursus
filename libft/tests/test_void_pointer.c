/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_void_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:33:10 by akroll            #+#    #+#             */
/*   Updated: 2022/03/22 17:07:59 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main()
{
	int a;
	char c;
	void *p;
	char *s;

	a = 8;
	c = 'c';
	//void pointer points to int a
	p = &a;
	//void pointer can't be dereferenced, need to cast it to int first, then dereference it
	printf("%d\n", *(int*)p);

	//same for char c
	p = &c;
	printf("%c\n", *(char*)p);

	//same for string s
	p = &s;
	s = "bzero";
	printf("%s\n", *(char**)p);

	return 0;
}
