/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 11:02:47 by akroll            #+#    #+#             */
/*   Updated: 2022/03/23 07:39:54 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
#define LIBFT_H

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(const char *s);
int		ft_strlcpy(char *dest, const char *src, unsigned int destsize);
char	*ft_strjoin(const char *s1, const char *s2);

int	ft_toupper(int c);
int	ft_tolower(int c);
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
int	ft_isascii(int c);

#endif
