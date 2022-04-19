/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstlast_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:48:52 by akroll            #+#    #+#             */
/*   Updated: 2022/04/19 17:32:41 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		main(void)
{
	char	str[] = "test";

	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;
	t_list	*elem4;
	t_list	*elem5;
	t_list	*elem6;
	t_list	*ret;

	if(!(elem1 = malloc(sizeof(t_list))))
		return (0);
	if(!(elem2 = malloc(sizeof(t_list))))
		return (0);
	if(!(elem3 = malloc(sizeof(t_list))))
		return (0);
	if(!(elem4 = malloc(sizeof(t_list))))
		return (0);
	if(!(elem5 = malloc(sizeof(t_list))))
		return (0);
	if(!(elem6 = malloc(sizeof(t_list))))
		return (0);

	elem1->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
	elem4->next = elem5;
	elem5->next = elem6;
	elem6->next = NULL;

	elem6->content = (void *)str;
	ret = ft_lstlast(elem1);
	printf("\n%s\n", (char *)ret->content);
}

//https://pythontutor.com/c.html#code=%23include%20%3Cstdio.h%3E%0A%0Atypedef%20struct%20s_list%0A%7B%0A%20%20%20%20void%20%20%20%20%20%20%20%20%20%20%20%20*content%3B%0A%20%20%20%20struct%20s_list%20%20%20%20*next%3B%0A%7D%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20t_list%3B%0A%0A%0At_list%20%20%20%20*ft_lstlast%28t_list%20*lst%29%0A%7B%0A%20%20%20%20while%20%28lst-%3Enext%20!%3D%20NULL%20%26%26%20lst%20!%3D%20NULL%29%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20lst%20%3D%20lst-%3Enext%3B%0A%20%20%20%20%7D%0A%20%20%20%20return%20%28lst%29%3B%0A%7D%0Aint%20%20%20%20%20%20%20%20main%28void%29%0A%7B%0A%20%20%20%20char%20%20%20%20str%5B%5D%20%3D%20%22test%22%3B%0A%0A%20%20%20%20t_list%20%20%20%20*elem1%3B%0A%20%20%20%20t_list%20%20%20%20*elem2%3B%0A%20%20%20%20t_list%20%20%20%20*elem3%3B%0A%20%20%20%20t_list%20%20%20%20*elem4%3B%0A%20%20%20%20t_list%20%20%20%20*elem5%3B%0A%20%20%20%20t_list%20%20%20%20*elem6%3B%0A%20%20%20%20t_list%20%20%20%20*ret%3B%0A%0A%20%20%20%20if%28!%28elem1%20%3D%20malloc%28sizeof%28t_list%29%29%29%29%0A%20%20%20%20%20%20%20%20return%20%280%29%3B%0A%20%20%20%20if%28!%28elem2%20%3D%20malloc%28sizeof%28t_list%29%29%29%29%0A%20%20%20%20%20%20%20%20return%20%280%29%3B%0A%20%20%20%20if%28!%28elem3%20%3D%20malloc%28sizeof%28t_list%29%29%29%29%0A%20%20%20%20%20%20%20%20return%20%280%29%3B%0A%20%20%20%20if%28!%28elem4%20%3D%20malloc%28sizeof%28t_list%29%29%29%29%0A%20%20%20%20%20%20%20%20return%20%280%29%3B%0A%20%20%20%20if%28!%28elem5%20%3D%20malloc%28sizeof%28t_list%29%29%29%29%0A%20%20%20%20%20%20%20%20return%20%280%29%3B%0A%20%20%20%20if%28!%28elem6%20%3D%20malloc%28sizeof%28t_list%29%29%29%29%0A%20%20%20%20%20%20%20%20return%20%280%29%3B%0A%0A%20%20%20%20elem1-%3Enext%20%3D%20elem2%3B%0A%20%20%20%20elem2-%3Enext%20%3D%20elem3%3B%0A%20%20%20%20elem3-%3Enext%20%3D%20elem4%3B%0A%20%20%20%20elem4-%3Enext%20%3D%20elem5%3B%0A%20%20%20%20elem5-%3Enext%20%3D%20elem6%3B%0A%20%20%20%20elem6-%3Enext%20%3D%20NULL%3B%0A%0A%20%20%20%20elem6-%3Econtent%20%3D%20%28void%20*%29str%3B%0A%20%20%20%20ret%20%3D%20ft_lstlast%28elem1%29%3B%0A%20%20%20%20printf%28%22%5Cn%25s%5Cn%22,%20%28char%20*%29ret-%3Econtent%29%3B%0A%7D&curInstr=31&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D
