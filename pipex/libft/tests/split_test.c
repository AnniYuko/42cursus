/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:38:34 by akroll            #+#    #+#             */
/*   Updated: 2022/04/19 17:33:36 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	main()
{
	char *s;
	char **arr;
	int	i;

	i = 0;
	s = "_42_is a cool place to be_";
	printf("input:\n\t\"%s\"\n", s);

	arr = ft_split(s, '_');

	printf("\noutput:\n");
	while (arr[i] != NULL)
	{
		printf("\tstring %d: %s\n", i, arr[i]);
		i++;
	}
	return 0;
}

// int	main()
// {
// 	char *s;
// 	char **arr;
// 	int	i;

// 	i = 0;
// 	s = "UN_DEUX_TROIS";
// 	printf("input:\n\t\"%s\"\n", s);

// 	arr = ft_split(s, '_');

// 	printf("\noutput:\n");
// 	while (arr[i] != NULL)
// 	{
// 		printf("\tstring %d: %s\n", i, arr[i]);
// 		i++;
// 	}
// 	return 0;
// }
