/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:50:33 by sadamant          #+#    #+#             */
/*   Updated: 2018/07/07 14:50:41 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	left_justify(t_format *f, char *str, int value)
{
	char	*num;

	num = precision_overfill(f, ft_numlen_abs(value));
	num = ft_strcat(num, ft_itoa_abs(value));
	if (f->flag->plus)
		*str++ = (value > 0) ? '+' : '-';
	else if (f->flag->space)
		*str++ = (value > 0) ? ' ' : '-';
	else
		(value < 0) ? *str++ = '-' : 0;
	while (*num)
		*str++ = *num++;
}

static void	right_justify(t_format *f, char *str, int value)
{
	char	*num;

	num = precision_overfill(f, ft_numlen_abs(value));
	num = ft_strcat(num, ft_itoa_abs(value));
	if (f->flag->plus || f->flag->space)
	{
		str += (f->flag->zero && f->precision == -1) ? 0 : ft_strlen(str) - ft_strlen(num) - 1;
		if (f->flag->plus)
			*str = (value > 0) ? '+' : '-';
		else if (f->flag->space)
			*str = (value > 0) ? ' ' : '-';
		str += (f->flag->zero && f->precision == -1) ? ft_strlen(str) - ft_strlen(num) : 1;
	}
	else
	{
		str += ft_strlen(str) - ft_strlen(num) - 1; // -1 is necessary for the sign
		(value < 0) ? *str++ = '-' : 0;
	}
	while (*num)
		*str++ = *num++;
}

static void	errorcheck_integer(t_format *f)
{
	if (f->flag->minus && f->flag->zero)
		put_error("Flag '0' is ignored when flag '-' is present.");
	if (f->flag->hash)
		error_undefined('#', 'd');
}

/*
** - : left justify, default is right justify
** + : add a plus when positive
** 0 : pad with 0s instead of with spaces
** . : maximum number of characters to be written. (pad with zeros)
*/

char	*handle_integer(t_format *f, int value)
{
	int		width;
	int		numlen;
	char	*out;

	errorcheck_integer(f);
	numlen = (f->precision > ft_numlen_abs(value)) ? f->precision : ft_numlen_abs(value);
	numlen += (value < 0 || f->flag->plus || f->flag->space) ? 1 : 0;
	width = (numlen > f->width) ? numlen : f->width;
	out = ft_memalloc(sizeof(char) * (width + 1)); //+1 for backslash zero?
	(f->flag->zero && f->precision == -1) ? ft_strfill(out, width, '0') : ft_strfill(out, width, ' ');
	printf("str: %s\n", out);
	(f->flag->minus) ? left_justify(f, out, value) : right_justify(f, out, value);
	return (out);
}
