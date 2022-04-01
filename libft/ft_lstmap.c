/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:08:17 by akroll            #+#    #+#             */
/*   Updated: 2022/04/01 14:30:46 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin_list;
	t_list	*new_node;

	while (lst != NULL)
	{
		new_node = ft_lstnew((*f)(lst->content));
		if (new_node == NULL)
			(*del)(lst->content);
		else
			ft_lstadd_back(&begin_list, new_node);
		lst = lst->next;
	}
	return (begin_list);
}
