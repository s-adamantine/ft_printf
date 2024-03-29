/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vadd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 14:25:33 by sadamant          #+#    #+#             */
/*   Updated: 2018/02/07 16:21:54 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	*vadd(const double *v1, const double *v2)
{
	int		i;
	int		n;
	double	*v3;

	i = -1;
	n = 0;
	while (v1[n])
		n++;
	v3 = ft_memalloc(sizeof(double) * (n + 1));
	while (++i < n)
		v3[i] = v1[i] + v2[i];
	v3[n] = '\0';
	return (v3);
}
