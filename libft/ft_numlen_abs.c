/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_abs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 00:17:16 by sadamant          #+#    #+#             */
/*   Updated: 2018/07/12 00:17:26 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** the length of the number without a - if it's negative.
*/
int		ft_numlen_abs(int num)
{
	int len;

	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}
