/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/08 20:39:00 by sadamant          #+#    #+#             */
/*   Updated: 2018/07/08 20:39:05 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	errorcheck_string(t_format *f)
{
	if (f->flag->zero)
		error_undefined('0', 's');
	if (f->flag->plus)
		error_undefined('+', 's');
	if (f->flag->space)
		error_undefined(' ', 's');
	if (f->flag->hash)
		error_undefined('#', 's');

}

/*
** - : left justify
** width : minimum characters to be printed, padded w spaces and not truncated,
** unless the precision is specified, then the string is truncated to the width.
** precision: the maximum number of characters to be printed. (can be 0!!)
*/
char	*handle_string(t_format *f, char *str)
{
	int		width;
	int		len;
	int		precision;
	int		offset;
	char	*out;

	len = (int)ft_strlen(str);
	errorcheck_string(f);
	//assign precision if it exists
	precision = (f->precision > -1) ? f->precision : len;
	//check initial width, untruncated
	width = (f->width > len) ? f->width : len;
	//check for truncated width.
	width = (f->width > precision) ? f->width : precision;
	out = ft_memalloc(sizeof(char) * (width + 1));
	ft_strfill(out, width, ' ');
	offset = (f->flag->minus) ? 0 : width - precision;
	// offset += (precision > len) ? precision - len : 0;
	ft_strncpy(out +  offset, str, (size_t)precision);
	f->charswritten = ft_strlen(out);
	return (out);
}
