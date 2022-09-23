/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:27:21 by akroll            #+#    #+#             */
/*   Updated: 2022/04/19 17:33:12 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>

int main()
{
	char str[] = "copy these overlapping parts";

	puts(str);
	ft_memmove(str + 5, str, 22);
	//memmove(str + 5, str, 22);

	puts(str);
	return 0;
}
