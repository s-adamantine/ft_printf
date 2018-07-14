/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 00:56:53 by sadamant          #+#    #+#             */
/*   Updated: 2018/07/11 00:57:05 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Gives the absolute numlength.
*/
int		ft_numlen_base(intmax_t num, int base)
{
	int		len;

	len = 0;
	if (num == 0)
		return (1);
	num = (num < 0) ? -num : num;
	while (num > 0)
	{
		len++;
		num /= base;
	}
	return (len);
}
