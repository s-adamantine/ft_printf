/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_content.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 07:51:38 by sadamant          #+#    #+#             */
/*   Updated: 2018/07/07 07:52:06 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	handle_integer(t_format *format, int value)
{
	if (format)
		printf("handling integer %d\n", value);
}

void	handle_content(va_list ap, t_list *lst)
{
	t_format *format;

	format = (t_format *) lst->content;
	if (format->specifier == 'd' || format->specifier == 'D')
		handle_integer(format, va_arg(ap, int));
}
