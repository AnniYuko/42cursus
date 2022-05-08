/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:08:17 by akroll            #+#    #+#             */
/*   Updated: 2022/04/12 11:56:29 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
			return (NULL);
		}
		else
			ft_lstadd_back(&new_list_begin, new_node);
		lst = lst->next;
	}
	return (new_list_begin);
}
