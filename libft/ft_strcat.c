/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 06:27:58 by sadamant          #+#    #+#             */
/*   Updated: 2017/09/09 06:46:55 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Concatenates source into dest, where dest has to have the available
** space necessary.
** If either dest or src is NULL, then it returns the other (assuming
** it's not null.)
*/

char	*ft_strcat(char *dest, const char *src)
{
	int i;

	i = 0;
	if (!dest)
		return ((char *) src);
	if (!src)
		return (dest);
	if (!dest && !src)
		return (NULL);
	while (dest[i])
		i++;
	while (*src)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}
