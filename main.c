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

int	ft_printf(const char *string, ...)
{
	va_list	ap;

	va_start(ap, string);
	for (int i = 0; i < 4; i++)
	{
		printf("%s\n", va_arg(ap, char *));
	}
	va_end(ap);
	check_for_format_specifier("testing %s this %2f %Sd %3e %%%%\n");
	return (1);
}

int	main(void)
{
	ft_printf("hello there", "testing", "for", "varying", "hello!");
	return (0);
}
