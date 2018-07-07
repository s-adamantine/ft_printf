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

void	handle_content(va_list ap, t_list *lst)
{
	char		*strout;
	t_format	*format;

	format = (t_format *) lst->content;
	strout = "";
	if (format->specifier == 'd' || format->specifier == 'D')
		strout = handle_integer(format, va_arg(ap, int));
	printf("strout: %s\n", strout);
}
