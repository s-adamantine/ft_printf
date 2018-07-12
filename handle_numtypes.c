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
char	*precision_overfill(t_format *f, int numlen)
{
	int		overfill;
	char	*num;

	overfill = 0;
	num = NULL;
	if (f->precision > numlen)
	{
		overfill = f->precision - numlen;
		num = ft_memalloc(sizeof(char) * (overfill + 1));
		ft_strfill(num, overfill, '0');
	}
	return (num);
}
