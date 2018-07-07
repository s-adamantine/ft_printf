/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_integer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:50:33 by sadamant          #+#    #+#             */
/*   Updated: 2018/07/07 14:50:41 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

// static char	*pad_left(t_format *f)
// {
// 	while (width - ft_numlen(value) > 0 && f->flag->minus == 0)
// 	{
// 		if (f->flag->minus == 0)
// 			out[i++] = (f->flag->zero == 1) ? '0' : ' ';
// 		width--;
// 	}
// 	while (width && *num)
// 		out[i++] = *num++;
// }

char	*get_integer_value(t_format *f, int value)
{
	if (f->flag->plus == 1 && value > 0)
		return (ft_strjoin("+", ft_itoa(value)));
	else
		return (ft_itoa(value));
}

// current progress: did right justification, now to do left
char	*handle_integer(t_format *f, int value)
{
	int		i;
	int		width;
	char	*out;
	char	*num;

	i = 0;
	width = (ft_numlen(value) > f->width) ? ft_numlen(value) : f->width;
	width += (f->flag->plus == 1) ? 1 : 0; //haven't tested this yet
	out = ft_memalloc(sizeof(char) * width);
	num = get_integer_value(f, value);
	//start dealing with padding
	//left justification, could probably be reused later
	printf("width is %d\n", width);
	//need to write this function for when there's a right justification
	while (width - ft_strlen(num) > 0 && f->flag->minus == 0)
	{
		if (f->flag->minus == 0)
			out[i++] = (f->flag->zero == 1) ? '0' : ' ';
		width--;
	}
	while (width && *num)
		out[i++] = *num++;
	return (out);
}
