/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 07:51:38 by sadamant          #+#    #+#             */
/*   Updated: 2018/07/07 07:52:06 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*handle_content(va_list ap, t_format *format)
{
	char		*strout;

	strout = "";
	if (format->specifier == 'd' || format->specifier == 'i')
		strout = handle_integer(format, va_arg(ap, int));
	if (format->specifier == 'u' || format->specifier == 'U' || format->specifier == 'D')
		strout = handle_unsignedint(format, va_arg(ap, unsigned int));
	if (format->specifier == 's')
		strout = handle_string(format, va_arg(ap, char *));
	if (format->specifier == 'X')
		strout = handle_upperhexa(format, va_arg(ap, unsigned int));
	if (format->specifier == 'x')
		strout = ft_strtolower(handle_upperhexa(format, va_arg(ap, unsigned int)));
	if (format->specifier == 'c' || format->specifier == 'C')
		strout = handle_character(format, va_arg(ap, unsigned int));
	return (strout);
}
