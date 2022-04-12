/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:48:32 by akroll            #+#    #+#             */
/*   Updated: 2022/04/12 15:55:24 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	main()
{
	char str[] = "ete.....petete";
	char charset[] = "tep";
	char *trimmed_str;

	trimmed_str = ft_strtrim(str, charset);
	printf("trimmed string: %s\n", trimmed_str);
	printf("length: %zu\n", ft_strlen(trimmed_str));

	return 0;
}
