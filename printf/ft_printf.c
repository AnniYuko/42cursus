/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akroll <akroll@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 16:22:31 by akroll            #+#    #+#             */
/*   Updated: 2022/04/19 17:35:54 by akroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprinft.h"

/*
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
*/

int	ft_printf(const char *format, ...)
{
	va_list	list;

	//initialize list
	va_start(list, format);

	// while (/*more_args_expected*/) {

	// 	/* Get next argument value. */
	// 	this_arg = va_arg(ap, type); /* va_arg() macro expands to an expression that has the type and value of the next argument in the call */
	// 	process(this_arg);
	// }
	// va_end(ap); /* finished argument processing */

}
