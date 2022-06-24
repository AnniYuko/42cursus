/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 20:13:16 by akroll            #+#    #+#             */
/*   Updated: 2022/03/28 14:16:00 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	- converts lowercase to uppercase (ASCII)
	- if not a lowercase letter or no uppercase defined (ie: ß) c is returned
*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 'a' - 'A';
	return (c);
}
