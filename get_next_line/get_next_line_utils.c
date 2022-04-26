/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:48:36 by akroll            #+#    #+#             */
/*   Updated: 2022/04/26 14:57:14 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *get_next_line(int fd)
{

}

/* issues:

- static char *content_after_newline
- always copies entire buffer (should stop after newline)
- what if entire file is empty? return empty string?
- what happens if read returns 0? quit while loop and return (newstring)
- read has an error -> return NULL

*/
