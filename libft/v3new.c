/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3new.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:57:43 by sadamant          #+#    #+#             */
/*   Updated: 2018/02/05 14:56:09 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	*v3new(double a, double b, double c)
{
	double	*v;

	v = ft_memalloc(sizeof(double) * 4);
	v[0] = a;
	v[1] = b;
	v[2] = c;
	v[3] = '\0';
	return (v);
}
