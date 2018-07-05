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

static char		*parse_length(t_format *format, char *str)
{
	if (ft_strncmp(str, "hh", 2) == 0)
	{
		format->length = 'H';
		return (str + 2);
	}
	if (ft_strncmp(str, "ll", 2) == 0)
	{
		format->length = 'L';
		return (str + 2);
	}
	if (*str == 'h' || *str == 'l' || *str == 'j' || *str == 'z')
	{
		format->length = *str;
		return (str + 1);
	}
	return (str);
}

static char		*parse_precision(t_format *format, char *str)
{
	char	*specifiers;

	specifiers = "sSpdDioOuUxXcCfF";
	if (ft_strchr(str, '.') == 0)
		return (str);
	while (*str && *str != '.' && !ft_strchr(specifiers, *str))
		str++;
	format->precision = ft_atoi(++str);
	if (format->precision == 0)
		return (str);
	return (str + ft_numlen(format->precision));
}

static void		parse_specifier(t_format *format, char c)
{
	char	*specifiers;

	specifiers = "sSpdDioOuUxXcCfF";
	if (ft_strchr(specifiers, c))
		format->specifier = c;
}

/*
** A valid format has a valid optional flag, a series of numbers with or
** without a full stop (for precision), a valid optional length, and a valid
** specifier.
*/
static int		valid_format(char *str)
{
	char	*flags;
	char	*specifiers;
	char	*lengths;

	flags = "+-#0";
	specifiers = "sSpdDioOuUxXcCfF";
	lengths = "hljz";
	if (!ft_isdigit(*str) && !ft_strchr(flags, *str) && *str != '.' &&
		!ft_strchr(specifiers, *str) && !ft_strchr(lengths, *str))
		return (0);
	while (ft_strchr(flags, *str))
		str++;
	while (ft_isdigit(*str))
		str++;
	*str == '.' ? str++ : 0;
	while (ft_isdigit(*str))
		str++;
	if (ft_strncmp(str, "hh", 2) == 0 || ft_strncmp(str, "ll", 2) == 0)
		str += 2;
	ft_strchr(lengths, *str) ? str++ : 0;
	if (!ft_strchr(specifiers, *str))
		return (0);
	return (1);
}

// needs to make sure that there's a specifier in there somewhere or you shouldn't
// initialize a new format.
// need to create a function that grabs one format specifier
int			check_for_format_specifier(t_format *format, char *string)
{
	while (*string)
	{
		if (*string == '%')
		{
			string++;
			if (valid_format(string))
			{
				printf("we found a valid format!\n");
				string = parse_flag(format, string);
				format->width = ft_atoi(string);
				string = parse_precision(format, string);
				string = parse_length(format, string);
				parse_specifier(format, *string);
			}
		}
		string++;
	}
	print_format(format);
	return (0);
}
