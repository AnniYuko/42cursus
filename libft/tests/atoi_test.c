/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:24:39 by akroll            #+#    #+#             */
/*   Updated: 2022/04/11 11:25:24 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	main()
{
	const char	*s;

	s = " 	 	    +409j300 ";
	printf("ft_atoi: %d\n", ft_atoi(s));
	printf("atoi:    %d\n", atoi(s));
}
