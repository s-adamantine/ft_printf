/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 19:45:29 by sadamant          #+#    #+#             */
/*   Updated: 2017/12/28 19:47:02 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"
# include <stdio.h> //get rid

typedef struct	s_flag
{
	int			minus;
	int			plus;
	int			hash;
	int			zero;
}				t_flag;

typedef struct	s_format
{
	int			n;
	int			width;
	int			precision;
	t_flag		*flag;
	char		specifier;
	char		**length;
}				t_format;

int		check_for_format_specifier(t_format *format, char *string);
int		ft_atoi_flags(const char *str);
void	error(int i);
