/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 15:20:42 by sadamant          #+#    #+#             */
/*   Updated: 2018/07/07 15:23:26 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** fills a given string with specified character
*/

char	*ft_strfill(char *str, int size, char c)
{
	int	i;

	i = 0;
	while (i < size)
		str[i++] = c;
	return (str);
}
