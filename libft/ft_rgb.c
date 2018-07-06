/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:37:40 by sadamant          #+#    #+#             */
/*   Updated: 2018/06/21 16:54:39 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_color		*ft_rgb(int color)
{
	t_color	*col;

	col = ft_memalloc(sizeof(t_color));
	if (col)
	{
		col->b = color % 256;
		color /= 256;
		col->g = color % 256;
		color /= 256;
		col->r = color;
		return (col);
	}
	return (NULL);
}
