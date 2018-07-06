/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 00:48:28 by sadamant          #+#    #+#             */
/*   Updated: 2018/07/06 00:48:36 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the length of the number, adding in +1 to length if it's negative.
*/

int		ft_numlen(int num)
{
	int len;

	len = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		len++;
	}
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}
