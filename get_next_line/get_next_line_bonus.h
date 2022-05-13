/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:57:02 by akroll            #+#    #+#             */
/*   Updated: 2022/05/13 11:58:28 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

char	*ft_string_move(char *dest, char *src, size_t len);
char	*split_line_from_static(char *static_string);
char	*ft_strjoin(char *s1, char *s2);
char	*read_line(int fd, char *static_string);
char	*get_next_line(int fd);
// utils
size_t	ft_strlen(const char *s);
size_t	get_length(const char *string);
bool	ft_strchr_bool(const char *s, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
