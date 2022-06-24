/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:48:32 by akroll            #+#    #+#             */
/*   Updated: 2022/04/19 17:33:50 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	main()
{
	char *trimmed_str;

	trimmed_str = ft_strtrim("", "abd");
	printf("trimmed string: %s\n", trimmed_str);
	printf("length: %zu\n", ft_strlen(trimmed_str));

	return 0;
}
