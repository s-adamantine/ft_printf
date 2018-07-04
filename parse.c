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

//can have more than one flag
//also needs to keep going up
static t_flag	*parse_flag(char *str)
{
	int		i;
	char	*flags;
	t_flag	*flag;

	i = 0;
	flags = "+-#0";
	if (!(flag = ft_memalloc(sizeof(t_flag))))
		error(1);
	printf("the string is: %s\n", str);
	while (ft_strchr(flags, str[i]))
	{
		(str[i] == '-') ? flag->minus = 1 : 0;
		(str[i] == '+') ? flag->plus = 1 : 0;
		(str[i] == '#') ? flag->hash = 1 : 0;
		(str[i] == '0') ? flag->zero = 1 : 0;
		i++;
	}
	return (flag);
}

static void		parse_specifier(t_format *format, char c)
{
	char	*specifiers;

	specifiers = "sSpdDioOuUxXcC";
	if (ft_strchr(specifiers, c))
		format->specifier = c;
}

// needs to make sure that there's a specifier in there somewhere or you shouldn't
// initialize a new fo anything.
int			check_for_format_specifier(t_format *format, char *string)
{
	int	i;
	int	n;
	char	*specifiers;

	specifiers = "sSpdDioOuUxXcC";
	i = 0;
	n = 0;
	//change to pointers!
	while (string[i])
	{
		if (string[i] == '%')
		{
			i++;
			format->flag = parse_flag(string + i);
			format->width = ft_atoi_flags(string + i);
			// format->precision = parse_precision(string + i);
			// format->length = ft_atoi(string);
			// format->specifier = parse_specifier(string);
			printf("format->width: %d\n", format->width);
			parse_specifier(format, string[i + 1]);
			if (ft_strchr(specifiers, string[i + 1]))
				n++;
		}
		i++;
	}
	return (0);
}
