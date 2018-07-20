/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 02:10:16 by sadamant          #+#    #+#             */
/*   Updated: 2018/07/21 02:10:21 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** Doesn't process precision, even though it can take them in as a parameter.
** Processes width, spaces.
*/
char	*handle_percent(t_format *f)
{
	int		width;
	int		place;
	char	*out;

	width = (f->width > 0) ? f-> width : 1;
	out = ft_memalloc(sizeof(char) * (width + 1));
	(f->flag->zero) ? ft_strfill(out, width, '0') : ft_strfill(out, width, ' ');
	place = (f->flag->minus) ? 0 : width - 1;
	out[place] = '%';
	f->charswritten = ft_strlen(out);
	return (out);
}
