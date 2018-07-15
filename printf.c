/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 19:36:26 by sadamant          #+#    #+#             */
/*   Updated: 2018/07/02 19:36:32 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	error_undefined(char flag, char specifier)
{
	ft_putstr_fd("Error: Flag '", 2);
	ft_putchar_fd(flag, 2);
	ft_putstr_fd("' results in undefined behavior with '", 2);
	ft_putchar_fd(specifier, 2);
	ft_putstr_fd("' conversion specifier\n", 2);
	exit(EXIT_FAILURE);
}

void	error(int i)
{
	if (i == 1)
		ft_putendl_fd("Error: memory not allocated.\n", 2);
	exit(EXIT_FAILURE);
}

void	put_error(char *str)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}

t_format	*init_format(void)
{
	t_format	*format;

	if (!(format = ft_memalloc(sizeof(t_format))))
		error(1);
	if (!(format->flag = ft_memalloc(sizeof(t_flag))))
		error(1);
	format->flag->plus = 0;
	format->flag->minus = 0;
	format->flag->hash = 0;
	format->flag->zero = 0;
	format->flag->space = 0;
	format->width = -1;
	format->precision = -1;
	format->specifier = '0';
	format->length = '0';
	format->value = NULL;
	format->type = 0;
	format->charswritten = 0;
	return (format);
}

int	ft_printf(const char *string, ...)
{
	va_list		ap;
	int			charswritten;

	charswritten = 0;
	va_start(ap, string);
	parse_input(ap, (char *)string, &charswritten);
	va_end(ap);
	return (charswritten);
}

// int	main(void)
// {
// 	int		i;
// 	double	d;
// 	char	c;
// 	char	*str;
// 	int		retor;
// 	int		retmine;
//
// 	i = -1;
// 	d = 3;
// 	c = 'a';
// 	str = "Hello me name is sharfy";
// 	retor = printf("%d\n", i);
// 	retmine = ft_printf("%d\n", i);
// 	printf("rets: original: %d, mine: %d\n", retor, retmine);
// 	return (0);
// }
