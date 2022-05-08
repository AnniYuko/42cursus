/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:45:08 by akroll            #+#    #+#             */
/*   Updated: 2022/04/15 12:32:02 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//tests for printable characters incl space (' ' = 32), DEL excluded (127)

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
