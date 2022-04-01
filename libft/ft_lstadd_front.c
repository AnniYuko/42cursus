/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:09:07 by akroll            #+#    #+#             */
/*   Updated: 2022/04/01 13:17:49 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*old_first_elem;

	if (*lst == NULL)
		*lst = new;
	else
	{
		old_first_elem = *lst;
		*lst = new;
		new->next = old_first_elem;
	}
}
