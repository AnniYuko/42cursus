/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:46:52 by akroll            #+#    #+#             */
/*   Updated: 2022/05/13 11:56:39 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>

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
