/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 15:14:52 by akroll            #+#    #+#             */
/*   Updated: 2022/04/19 17:33:45 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <string.h>

int main()
{
	char *dest;
	char *dest_;
	const char *src;

	dest  = "rrrrrrrrrrrrrrr";
	dest_ = "rrrrrrrrrrrrrrr";
	src = "lorem ipsum dolor sit";
	printf("ft_strlcat\n\t%zu\n", ft_strlcat(dest_, src, 0));
	printf("\t%s\n", dest_);

	printf("strlcat\n\t%lu\n", strlcat(dest, src, 0));
	printf("\t%s\n", dest);
}
