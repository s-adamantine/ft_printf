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

	if (f->precision > ft_numlen(value))
	{
		num = ft_memalloc(sizeof(char) * (f->precision - ft_numlen(value) + 1));
		ft_strfill(num, f->precision - ft_numlen(value), '0');
	}
	else
		num = NULL;
	num = ft_strcat(num, ft_itoa(value));
	(f->flag->plus && value > 0) ? *str++ = '+' : 0;
	while (*num)
		*str++ = *num++;
}

// need to take into account the precision.
static void	right_justify(t_format *f, char *str, int value)
{
	char	*num;

	if (f->precision > ft_numlen(value))
	{
		num = ft_memalloc(sizeof(char) * (f->precision - ft_numlen(value) + 1));
		ft_strfill(num, f->precision - ft_numlen(value), '0');
	}
	else
		num = NULL;
	if (f->flag->plus)
	{
		num = ft_strcat(num, ft_itoa_abs(value));
		str += (f->flag->zero) ? 0 : ft_strlen(str) - ft_strlen(num) - 1;
		*str = (value > 0) ? '+' : '-';
		str += (f->flag->zero) ? ft_strlen(str) - ft_strlen(num) : 1;
	}
	else
	{
		num = ft_strcat(num, ft_itoa(value));
		str += ft_strlen(str) - ft_strlen(num);
	}
	while (*num)
		*str++ = *num++;
}

static void	errorcheck_integer(t_format *f)
{
	if (f->flag->minus && f->flag->zero)
		put_error("Flag '0' is ignored when flag '-' is present.");
}

/*
** - : left justify, default is right justify
** + : add a plus when positive
** 0 : pad with 0s instead of with spaces
** . : maximum number of characters to be written. (pad with zeros)
*/
char	*handle_integer(t_format *f, int value)
{
	int		i;
	int		width;
	char	*out;

	i = 0;
	errorcheck_integer(f);
	width = (ft_numlen(value) > f->width) ? ft_numlen(value) : f->width;
	width = (f->precision > width) ? f->precision : width;
	width += (f->flag->plus && ((width == ft_numlen(value)) || f->precision > ft_numlen(value))) ? 1 : 0;
	out = ft_memalloc(sizeof(char) * (width + 1)); //+1 for backslash zero?
	(f->flag->zero && f->precision == -1) ? ft_strfill(out, width, '0') : ft_strfill(out, width, ' ');
	(f->flag->minus) ? left_justify(f, out, value) : right_justify(f, out, value);
	return (out);
}
