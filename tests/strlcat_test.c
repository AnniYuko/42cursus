/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:14:52 by akroll            #+#    #+#             */
/*   Updated: 2022/04/08 15:15:26 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <string.h>

int	main()
{
	int	size = 0;
	char dest[20] = "bla ";
	char dest_[20] = "bla ";

	printf("strlcat:    %lu\n", strlcat(dest, "concat this", size));
	printf("ft_strlcat: %lu\n", ft_strlcat(dest_, "concat this", size));

	printf("\nresulting strings:\n");
	printf("\tstrlcat:    %s\n", dest);
	printf("\tft_strlcat: %s\n", dest_);
}
