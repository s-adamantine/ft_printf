/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 19:37:08 by sadamant          #+#    #+#             */
/*   Updated: 2018/07/02 19:37:22 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		check_for_format_specifier(const char *string)
{
	int	i;
	int	n;
	char	*specifiers;

	i = 0;
	n = 0;
	specifiers = "sSpdDioOuUxXcC";
	while (string[i])
	{
		if (string[i] == '%')
		{
			if (ft_strchr(specifiers, string[i + 1]))
				n++;
			i++;
		}
		i++;
	}
	printf("%d\n", n);
	return (0);
}
