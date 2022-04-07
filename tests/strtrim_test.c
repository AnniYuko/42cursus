/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:48:32 by akroll            #+#    #+#             */
/*   Updated: 2022/04/07 15:49:46 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	main()
{
	char str[] = "..,,..mein string..hello....:";
	char charset[] = ",.:";
	printf("trimmed string: %s\n", ft_strtrim(str, charset));

	return 0;
}
