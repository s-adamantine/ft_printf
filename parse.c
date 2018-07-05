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

static void		parse_length(t_format *format, char *str)
{
	if (ft_strncmp(str, "hh", 3))
		format->length = "hh";
	else if (ft_strncmp(str, "ll", 2))
		format->length = "ll";
	else if (*str == 'h' || *str == 'l' || *str == 'j' || *str == 'z')
		ft_strncpy(format->length, str, 1);
}

static void		parse_specifier(t_format *format, char c)
{
	char	*specifiers;

	specifiers = "sSpdDioOuUxXcC";
	if (ft_strchr(specifiers, c))
		format->specifier = c;
}

static int		parse_precision(char *str)
{
	while (*str && *str != '.')
		str++;
	return (ft_atoi(++str));
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
			format->precision = parse_precision(string + i);
			parse_length(format, string);
			// parse_specifier(format, string);
			printf("format->width: %d\n", format->width);
			printf("format->precision: %d\n", format->precision);
			printf("format->length: %s\n", format->length);
			parse_specifier(format, string[i + 1]);
			if (ft_strchr(specifiers, string[i + 1]))
				n++;
		}
		i++;
	}
	return (0);
}
