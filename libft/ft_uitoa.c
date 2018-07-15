/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 19:37:31 by sadamant          #+#    #+#             */
/*   Updated: 2018/07/12 19:37:37 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		*ft_uitoa(uintmax_t n)
{
	int		len;
	char	*res;

	len = ft_unumlen(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (--len >= 0)
	{
		res[len] = (n % 10) + '0';
		n = n / 10;
	}
	return (res);
}
