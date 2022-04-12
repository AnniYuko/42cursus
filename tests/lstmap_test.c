/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:08:17 by akroll            #+#    #+#             */
/*   Updated: 2022/04/12 11:56:22 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#define INT_DATA

void	ft_list_print(t_list *begin_list)
{
	int	i;

	i = 0;
	if (begin_list == NULL)
		printf("List is empty\n");

	while (begin_list != NULL)
	{
		printf("elem %d (%p)\n", i, begin_list);

		#ifdef INT_DATA
		printf("\tdata: %d\n", *((int*)(begin_list->content)));
		#endif
		#ifdef STRS_DATA
		printf("\tdata: %s\n", *((char**)(begin_list->content)));
		#endif

		printf("\tnext: %p\n\n", begin_list->next);
		begin_list = begin_list->next;
		i++;
	}
}

void	ft_del(void *content)
{
	free(content);
}

void	*ft_change_uneven_nums(void *content)
{
	int	*result;

	result = malloc(sizeof(int));

	if (*(int *)content % 2)
		*result = 42;
	else
		*result = *(int *)content;
	return (result);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list_begin;
	t_list	*new_node;

	new_list_begin = NULL;
	while (lst != NULL)
	{
		new_node = ft_lstnew((*f)(lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&new_list_begin, del);
			ft_lstdelone(new_node, del);
		}
		else
			ft_lstadd_back(&new_list_begin, new_node);
		lst = lst->next;
	}
	return (new_list_begin);
}

int	main(void)
{
	t_list	*lst;
	t_list	*resulting_list;
	int		uneven;
	int		even;

	lst = NULL;
	uneven = 3;
	even = 2;
	ft_lstadd_front(&lst, ft_lstnew(&uneven));
	ft_lstadd_front(&lst, ft_lstnew(&even));
	ft_lstadd_front(&lst, ft_lstnew(&uneven));

	resulting_list = ft_lstmap(lst, ft_change_uneven_nums, ft_del);
	printf("list: -----------------------------\n");
	ft_list_print(lst);
	printf("new list, function applied --------\n");
	ft_list_print(resulting_list);
}
