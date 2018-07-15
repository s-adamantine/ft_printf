/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 10:19:03 by sadamant          #+#    #+#             */
/*   Updated: 2018/07/13 10:19:08 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_uitoa_base(uintmax_t value, int base)
{
	int				len;
	char			*str;
	int				times;

	str = NULL;
	len = ft_unumlen_base(value, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	times = len;
	str[len--] = '\0';
	while (times--)
	{
		if (value % base < 10)
			str[len--] = value % base + '0';
		else
			str[len--] = value % base - 10 + 'A';
		value /= base;
	}
	return (str);
}
