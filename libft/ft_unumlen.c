/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unumlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 19:49:14 by sadamant          #+#    #+#             */
/*   Updated: 2018/07/12 19:49:18 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_unumlen(unsigned int n)
{
   int len;

   len = 0;
   if (n == 0)
	   return (1);
   while (n != 0)
   {
	   n = n / 10;
	   len++;
   }
   return (len);
}
