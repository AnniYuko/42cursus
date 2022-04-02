/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:09:07 by akroll            #+#    #+#             */
/*   Updated: 2022/04/01 13:15:11 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/ft_list.h"

int	main()
{
	t_list	**lst;
	t_list	*old_first_elem;
	t_list	*added;
	char	*content1;
	char	*content2;

	char s1[] = "old_first_elem";
	char s2[] = "added";

	content1 = s1;
	content2 = s2;

	old_first_elem = ft_lstnew(content1);
	lst = &old_first_elem;
	//*lst = old_first_elem;

	added = ft_lstnew(content2);
	printf("begin of list: %p\n\nelem %p\n\tcontent: %s\n\tnext: %p\n", *lst, old_first_elem, old_first_elem->content, old_first_elem->next);
	ft_lstadd_front(lst, added);

	printf("\nafter ft_lstadd_front\n\nbegin of list: %p\n", *lst);
	printf("\nelem %p\n\tcontent: %s\n\tnext: %p\n", added, added->content, added->next);
	printf("\nelem %p\n\tcontent: %s\n\tnext: %p\n", added->next, added->next->content, added->next->next);
}

//visualized:
//https://pythontutor.com/c.html#code=%23include%20%3Cstdio.h%3E%0A%0Atypedef%20struct%20s_list%0A%7B%0A%20%20%20%20void%20%20%20%20%20%20%20%20%20%20%20%20*content%3B%0A%20%20%20%20struct%20s_list%20%20%20%20*next%3B%0A%7D%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20%20t_list%3B%0A%0A%0At_list%20*ft_lstnew%28void%20*content%29%0A%7B%0A%20%20%20%20t_list%20*elem%3B%0A%0A%20%20%20%20elem%20%3D%20malloc%28sizeof%28t_list%29%29%3B%0A%20%20%20%20if%20%28elem%20%3D%3D%20NULL%29%0A%20%20%20%20%20%20%20%20return%28NULL%29%3B%0A%0A%20%20%20%20elem-%3Econtent%20%3D%20content%3B%0A%20%20%20%20elem-%3Enext%20%3D%20NULL%3B%0A%20%20%20%20return%28elem%29%3B%0A%7D%0A%0Avoid%20%20%20%20ft_lstadd_front%28t_list%20**lst,%20t_list%20*new%29%0A%7B%0A%20%20%20%20t_list%20%20%20%20*old_first_elem%3B%0A%0A%20%20%20%20if%20%28*lst%20%3D%3D%20NULL%29%0A%20%20%20%20%20%20%20%20*lst%20%3D%20new%3B%0A%20%20%20%20else%0A%20%20%20%20%7B%0A%20%20%20%20%20%20%20%20old_first_elem%20%3D%20*lst%3B%0A%20%20%20%20%20%20%20%20*lst%20%3D%20new%3B%0A%20%20%20%20%20%20%20%20new-%3Enext%20%3D%20old_first_elem%3B%0A%20%20%20%20%7D%0A%7D%0A%0Aint%20%20%20%20main%28%29%0A%7B%0A%20%20%20%20t_list%20%20%20%20**lst%3B%0A%20%20%20%20t_list%20%20%20%20*old_first_elem%3B%0A%20%20%20%20t_list%20%20%20%20*added%3B%0A%20%20%20%20char%20%20%20%20*content1%3B%0A%20%20%20%20char%20%20%20%20*content2%3B%0A%0A%0A%20%20%20%20char%20s1%5B%5D%20%3D%20%22old_first_elem%22%3B%0A%20%20%20%20char%20s2%5B%5D%20%3D%20%22added%22%3B%0A%0A%20%20%20%20content1%20%3D%20s1%3B%0A%20%20%20%20content2%20%3D%20s2%3B%0A%0A%20%20%20%20old_first_elem%20%3D%20ft_lstnew%28content1%29%3B%0A%20%20%20%20lst%20%3D%20%26old_first_elem%3B%0A%20%20%20%20//*lst%20%3D%20old_first_elem%3B%0A%0A%20%20%20%20added%20%3D%20ft_lstnew%28content2%29%3B%0A%20%20%20%20printf%28%22begin%20of%20list%3A%20%25p%5Cn%5Cnelem%20%25p%5Cn%5Ctcontent%3A%20%25s%5Cn%5Ctnext%3A%20%25p%5Cn%22,%20*lst,%20old_first_elem,%20old_first_elem-%3Econtent,%20old_first_elem-%3Enext%29%3B%0A%20%20%20%20ft_lstadd_front%28lst,%20added%29%3B%0A%0A%20%20%20%20printf%28%22%5Cnafter%20ft_lstadd_front%5Cn%5Cnbegin%20of%20list%3A%20%25p%5Cn%22,%20*lst%29%3B%0A%20%20%20%20printf%28%22%5Cnelem%20%25p%5Cn%5Ctcontent%3A%20%25s%5Cn%5Ctnext%3A%20%25p%5Cn%22,%20added,%20added-%3Econtent,%20added-%3Enext%29%3B%0A%20%20%20%20printf%28%22%5Cnelem%20%25p%5Cn%5Ctcontent%3A%20%25s%5Cn%5Ctnext%3A%20%25p%5Cn%22,%20added-%3Enext,%20added-%3Enext-%3Econtent,%20added-%3Enext-%3Enext%29%3B%0A%7D&curInstr=35&mode=display&origin=opt-frontend.js&py=c_gcc9.3.0&rawInputLstJSON=%5B%5D
