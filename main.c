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
}

static t_format	*init_format(void)
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
	format->width = 0;
	format->precision = 0;
	format->specifier = '\0';
	format->length = '\0';
	return (format);
}

// need to create a function initializing all the formats
// need to instantiate a list of formats
int	ft_printf(const char *string, ...)
{
	// va_list		ap;
	t_format	*format;

	format = init_format();
	check_for_format_specifier(format, (char *)string);
	// va_start(ap, string);
	// for (int i = 0; i < 1; i++)
	// {
	// 	printf("%s\n", va_arg(ap, char *));
	// }
	// va_end(ap);

	return (1);
}

int	main(void)
{
	int	i;
	char	*str;

	i = 5;
	str = "21";
	ft_printf("hello I'm testing three %20.3jf\n");
	return (0);
}
