/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:08:17 by akroll            #+#    #+#             */
/*   Updated: 2022/04/11 16:47:59 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list_begin;
	t_list	*new_node;
	t_list	*previous_node;

	previous_node = NULL;
	while (lst != NULL)
	{
		new_node = ft_lstnew((*f)(lst->content));
		if (new_node == NULL)
		{
			if (previous_node != NULL)
				previous_node->next = lst->next;
			previous_node = lst;
			lst = lst->next;
			ft_lstdelone(previous_node, del);
		}
		else
			ft_lstadd_back(&new_list_begin, new_node);
		previous_node = lst;
		lst = lst->next;
	}
	return (new_list_begin);
}
