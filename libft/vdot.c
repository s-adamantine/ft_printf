/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vdot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 06:04:15 by sadamant          #+#    #+#             */
/*   Updated: 2018/02/06 14:10:19 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	vdot(const double *v1, const double *v2, int n)
{
	int		i;
	double	dot;

	i = -1;
	dot = 0;
	while (++i < n)
		dot += (v1[i] * v2[i]);
	return (dot);
}