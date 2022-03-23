/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:27:15 by akroll            #+#    #+#             */
/*   Updated: 2022/03/22 14:28:00 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strjoin(const char *s1, const char *s2)
{
    char *concat_str;
    int i;
    int j;

    i = 0;
    j = 0;
    printf("size s1: %d\nsize s2: %d\n", ft_strlen(s1), ft_strlen(s2));
    concat_str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
    if (!concat_str)
        return(NULL);
    while (s1[i])
    {
        concat_str[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        concat_str[i] = s2[j];
        i++;
        j++;
    }
    concat_str[i] = '\0';
    return(concat_str);
}

int main()
{
    char const *s1;
    char const *s2;

    s1 = "hello";
    s2 = "world";

    ft_strjoin(s1, s2);
    return(0);
}
