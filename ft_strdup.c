/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:50:17 by akroll            #+#    #+#             */
/*   Updated: 2022/03/22 13:51:38 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *ft_strdup(char *src)
{
	char *dest;

	dest = malloc(sizeof(char) * (str_len(src) + 1));
	ft_strcpy(dest, src);
	return (dest);
}
