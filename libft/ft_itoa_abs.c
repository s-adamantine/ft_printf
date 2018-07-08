/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_abs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 21:48:44 by sadamant          #+#    #+#             */
/*   Updated: 2017/10/01 16:19:44 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*
** returns the absolute value of the number passed in to it.
*/

static int	num_len(int n)
{
	int len;

	len = 0;
	if (n == 0)
	{
		return (1);
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_itoa_abs(int n)
{
	int		len;
	char	*res;

	len = num_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n == -2147483648)
		return (ft_strcpy(res, "-2147483648"));
	if (n < 0)
	{
		n = n * -1;
	}
	while (--len >= 0)
	{
		res[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (res);
}
