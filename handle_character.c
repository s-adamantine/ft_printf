/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_character.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 17:18:40 by sadamant          #+#    #+#             */
/*   Updated: 2018/07/12 17:18:44 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	errorcheck_character(t_format *f)
{
	if (f->flag->hash)
		error_undefined('#', 'c');
	if (f->flag->plus)
		error_undefined('+', 'c');
	if (f->flag->zero)
		error_undefined('0', 'c');
	if (f->flag->space)
		error_undefined(' ', 'c');
	if (f->precision > 0)
		put_error("Error: precision used with 'c' conversion specifier, resulting in undefined behavior.");
}

/*
** '-' : left justify, as per
** must account for width
** no precision!!
*/
char	*handle_character(t_format *f, unsigned int c)
{
	int		width;
	char	*out;

	errorcheck_character(f);
	width = (f->width > 1) ? f->width : 1;
	out = ft_memalloc(sizeof(char) * (width + 1));
	ft_strfill(out, width, ' ');
	if (f->flag->minus)
		out[0] = c;
	else
		out[width - 1] = c;
	return (out);
}
