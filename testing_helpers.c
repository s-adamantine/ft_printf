/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 22:19:50 by sadamant          #+#    #+#             */
/*   Updated: 2018/07/05 22:19:54 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_format(t_format *format)
{
	printf("flags: +:%d, -:%d, #:%d, 0:%d\n", format->flag->plus, format->flag->minus, format->flag->hash, format->flag->zero);
	printf("width: %d\n", format->width);
	printf("precision: %d\n", format->precision);
	printf("length: %c\n", format->length);
	printf("specifer: %c\n", format->specifier);
}
