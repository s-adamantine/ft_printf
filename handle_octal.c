/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 16:56:42 by sadamant          #+#    #+#             */
/*   Updated: 2018/07/13 16:56:49 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	left_justify(t_format *f, char *str, uintmax_t value)
{
	char	*num;

	num = (f->flag->hash && value != 0) ? ft_strdup("0") : ft_strdup("");
	num = ft_strjoin(num, precision_overfill(f, ft_unumlen_base(value, 8)));
	num = ft_strjoin(num, ft_uitoa_base(value, 8));
	while (*num)
		*str++ = *num++;
}

static void	right_justify(t_format *f, char *str, uintmax_t value)
{
	char	*num;

	num = (f->flag->hash && value != 0 && f->precision < ft_unumlen_base(value, 8)) ? ft_strdup("0") : ft_strdup("");
	num = ft_strjoin(num, precision_overfill(f, ft_unumlen_base(value, 8)));
	num = ft_strjoin(num, ft_uitoa_base(value, 8));
	str += ft_strlen(str) - ft_strlen(num);
	while (*num)
		*str++ = *num++;
}

static void	errorcheck_octal(t_format *f)
{
	if (f->flag->plus)
		error_undefined('+', 'o');
	if (f->flag->space)
		error_undefined(' ', 'o');
}
/*
** '-' : left justify
** '#' : preceed with 0X for values different than zero
** '0' : leftpads with zero.
** width, and precision
** . : the minimum number of digits to be written. if the value to be written is
** shorter than this number, then it's padded with leading zeros.
*/
char	*handle_octal(t_format *f, uintmax_t value)
{
	int		width;
	int		numlen;
	char	*out;

	errorcheck_octal(f);
	numlen = (f->precision > ft_unumlen_base(value, 8)) ? f->precision : ft_unumlen_base(value, 8);
	numlen += (f->flag->hash) ? 1 : 0;
	width = (numlen > f->width) ? numlen : f->width;
	out = ft_memalloc(sizeof(char) * (width + 1));
	(f->flag->zero && f->precision == -1) ? ft_strfill(out, width, '0') : ft_strfill(out, width, ' ');
	(f->flag->minus) ? left_justify(f, out, value) : right_justify(f, out, value);
	f->charswritten = ft_strlen(out);
	return (out);
}
