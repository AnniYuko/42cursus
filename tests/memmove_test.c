/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:27:21 by akroll            #+#    #+#             */
/*   Updated: 2022/03/25 14:41:23 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libft/ft_memmove.c"

int main()
{
	char str[] = "copy this to .....";

	puts(str);
	ft_memmove(str + 13, str + 5, 4);
	//ft_memmove(str + 3, str, 9);
	puts(str);
	return 0;
}