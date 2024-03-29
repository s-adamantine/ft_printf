/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 18:28:36 by sadamant          #+#    #+#             */
/*   Updated: 2017/10/04 12:10:51 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Edited from the original: if either s1 or s2 doesn't exist, now returns the
** other (used to return null).
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*joined;

	i = 0;
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	joined = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (joined)
	{
		while (*s1)
			joined[i++] = *s1++;
		while (*s2)
			joined[i++] = *s2++;
		joined[i] = '\0';
		return (joined);
	}
	return (NULL);
}
