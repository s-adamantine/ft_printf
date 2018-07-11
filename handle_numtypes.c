/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_numtypes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 23:13:10 by sadamant          #+#    #+#             */
/*   Updated: 2018/07/11 23:13:18 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
** Pads extra zeros as required by precision.
*/
char	*allocate_precision_overfill(t_format *f, int numlen)
{
	char	*num;

	num = NULL;
	if (f->precision > numlen)
	{
		num = ft_memalloc(sizeof(char) * (f->precision - numlen + 1));
		ft_strfill(num, f->precision - numlen, '0');
	}
	return (num);
}
