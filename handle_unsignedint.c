/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsignedint.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 18:38:08 by sadamant          #+#    #+#             */
/*   Updated: 2018/07/12 18:38:15 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	left_justify(t_format *f, char *str, unsigned int value)
{
	char	*num;

	num = precision_overfill(f, ft_unumlen(value));
	num = ft_strjoin(num, ft_uitoa(value));
	while (*num)
		*str++ = *num++;
}

static void	right_justify(t_format *f, char *str, unsigned int value)
{
	char	*num;

	num = precision_overfill(f, ft_unumlen(value));
	num = ft_strjoin(num, ft_uitoa(value));
	str += ft_strlen(str) - ft_strlen(num);
	while (*num)
		*str++ = *num++;
}

static void		errorcheck_unsignedint(t_format *f)
{
	if (f->flag->minus && f->flag->zero)
		put_error("Flag '0' is ignored when flag '-' is present.");
	if (f->flag->plus)
		error_undefined('+', 'u');
	if (f->flag->hash)
		error_undefined('#', 'u');
	if (f->flag->space)
		error_undefined(' ', 'u');
}

/*
** handle precision, width, left justification, 0 flag,
** grabbing it as unsigned int means that it automatically casts it.
** looks like it follows the integer formatting exactly the same way, except that
** it doesn't take into account the numlen in the value calculation.
*/
char			*handle_unsignedint(t_format *f, unsigned int value)
{
	int		numlen;
	int		width;
	char	*out;

	errorcheck_unsignedint(f);
	numlen = (f->precision > ft_unumlen(value)) ? f->precision : ft_unumlen(value);
	width = (numlen > f->width) ? numlen : f->width;
	out = ft_memalloc(sizeof(char) * (width + 1));
	(f->flag->zero && f->precision == -1) ? ft_strfill(out, width, '0') : ft_strfill(out, width, ' ');
	(f->flag->minus) ? left_justify(f, out, value) : right_justify(f, out, value);
	f->charswritten = ft_strlen(out);
	return (out);
}
