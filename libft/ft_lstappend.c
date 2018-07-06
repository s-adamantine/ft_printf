/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 11:33:14 by sadamant          #+#    #+#             */
/*   Updated: 2018/07/06 11:37:02 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** appends a new link to the head of the link alst. if alst doesn't exist,
** the new becomes the head of the link.
*/

void	ft_lstappend(t_list **alst, t_list *new)
{
	if (!(*alst)->content && !(*alst)->next)
		(*alst) = new;
	else
	{
		while ((*alst)->next)
			(*alst) = (*alst)->next;
		(*alst)->next = new;
	}
}
