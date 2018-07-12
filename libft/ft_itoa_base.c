/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:40:18 by sadamant          #+#    #+#             */
/*   Updated: 2018/05/17 17:43:58 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Written for an exam.
** Result is displayed in uppercase.
** If base is 10 and value is negative, the resulting string is preceded with a
** minus sign (-). With any other base, value is always considered unsigned.
*/

char	*ft_itoa_base(int value, int base)
{
	int				len;
	int				neg;
	unsigned int	num;
	char			*str;
	int				times;

	if (value == -2147483648 && base == 10)
		return ("-2147483648");
	str = NULL;
	len = ft_numlen_base(value, base);
	neg = (base == 10 && value < 0) ? 1 : 0;
	num = (value < 0) ? (unsigned int)-value : value;
	str = (char *)malloc(sizeof(char) * (len + neg + 1));
	times = len;
	str[len--] = '\0';
	while (times--)
	{
		if (num % base < 10)
			str[len--] = num % base + '0';
		else
			str[len--] = num % base - 10 + 'A';
		num /= base;
	}
	if (neg)
		str[0] = '-';
	return (str);
}
