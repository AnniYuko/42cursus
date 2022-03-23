/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 21:34:12 by akroll            #+#    #+#             */
/*   Updated: 2022/03/21 21:38:26 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	- converts upper- to lowercase (ASCII)
	- if not an uppercase letter or no lowercase defined (ie: ß) c is returned
*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 'a' - 'A';
	return(c);
}
