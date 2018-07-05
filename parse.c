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

static char		*parse_flag(t_format *format, char *str)
{
	char	*flags;

	flags = "+-#0";
	while (ft_strchr(flags, *str))
	{
		(*str == '-') ? format->flag->minus = 1 : 0;
		(*str == '+') ? format->flag->plus = 1 : 0;
		(*str == '#') ? format->flag->hash = 1 : 0;
		(*str == '0') ? format->flag->zero = 1 : 0;
		str++;
	}
	return (str);
}

static void		parse_length(t_format *format, char *str)
{
	if (ft_strncmp(str, "hh", 3))
		format->length = 'H';
	else if (ft_strncmp(str, "ll", 2))
		format->length = 'L';
	else if (*str == 'h' || *str == 'l' || *str == 'j' || *str == 'z')
		format->length = *str;
}

// static void		parse_specifier(t_format *format, char c)
// {
// 	char	*specifiers;
//
// 	specifiers = "sSpdDioOuUxXcC";
// 	if (ft_strchr(specifiers, c))
// 		format->specifier = c;
// }

//need to grab a tab so it doesn't check for the entire string
static int		parse_precision(char *str)
{
	if (ft_strchr(str, '.') == 0)
		return (0);
	while (*str && *str != '.')
		str++;
	return (ft_atoi(++str));
}

// needs to make sure that there's a specifier in there somewhere or you shouldn't
// initialize a new format.
// need to create a function that grabs one format specifier
int			check_for_format_specifier(t_format *format, char *string)
{
	int	n;
	char	*specifiers;

	specifiers = "sSpdDioOuUxXcC";
	n = 0;
	//change to pointers!
	while (*string)
	{
		if (*string == '%')
		{
			string++;
			string = parse_flag(format, string);
			format->width = ft_atoi(string);
			format->precision = parse_precision(string);
			parse_length(format, string);
			// parse_specifier(format, string);
			// parse_specifier(format, string[i + 1]);
			// if (ft_strchr(specifiers, string[i + 1]))
			// 	n++;
		}
		string++;
	}
	print_format(format);
	return (0);
}
