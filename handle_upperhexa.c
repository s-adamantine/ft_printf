/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_upperhexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 00:44:44 by sadamant          #+#    #+#             */
/*   Updated: 2018/07/11 00:44:49 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	left_justify(t_format *f, char *str, int value)
{
	char	*num;

	num = allocate_precision_overfill(f, ft_numlen_base(value, 16));
	num = ft_strcat(num, ft_itoa_base(value, 16));
	while (*num)
		*str++ = *num++;
}

static void	right_justify(t_format *f, char *str, int value)
{
	char	*num;

	num = allocate_precision_overfill(f, ft_numlen_base(value, 16));
	num = ft_strcat(num, ft_itoa_base(value, 16)); //this is where it's diff from integers
	str += ft_strlen(str) - ft_strlen(num);
	while (*num)
		*str++ = *num++;
}

static void	errorcheck_hexa(t_format *f)
{
	if (f->flag->plus)
		put_error("Flag '+' results in undefined behavior with 'X' conversion specifier");
}
/*
** '-' : left justify
** '#' : preceed with 0X for values different than zero
** '0' : leftpads with zero. //test?
** width, and precision
** . : the minimum number of digits to be written. if the value to be written is
** shorter than this number, then it's padded with leading zeros.
*/
char	*handle_upperhexa(t_format *f, int value)
{
	int		width;
	int		numlen;
	char	*out;

	errorcheck_hexa(f);
	numlen = (f->precision > ft_numlen_base(value, 16)) ? f->precision : ft_numlen_base(value, 16);
	numlen += (value < 0 || f->flag->plus) ? 1 : 0;
	width = (numlen > f->width) ? numlen : f->width;
	out = ft_memalloc(sizeof(char) * (width + 1));
	(f->flag->zero && f->precision == -1) ? ft_strfill(out, width, '0') : ft_strfill(out, width, ' ');
	(f->flag->minus) ? left_justify(f, out, value) : right_justify(f, out, value);
	return (out);
}