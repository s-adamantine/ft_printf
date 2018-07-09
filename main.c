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
	format->width = -1;
	format->precision = -1;
	format->specifier = '0';
	format->length = '0';
	format->value = NULL;
	format->type = 0;
	return (format);
}

int	ft_printf(const char *string, ...)
{
	va_list		ap;

	va_start(ap, string);
	parse_input(ap, (char *)string);
	va_end(ap);
	return (1);
}

int	main(void)
{
	int		i;
	double	d;
	char	*str;

	i = 3242;
	d = 3;
	str = "Hello me name is sharfy";
	printf("testing the original: %25s\n", str);
	ft_printf("testing my own: %25s\n", str);
	return (0);
}
