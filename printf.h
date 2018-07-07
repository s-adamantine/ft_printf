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

typedef enum	e_type
{
	INT,
	STRING
}				t_type;

typedef struct	s_flag
{
	int			minus;
	int			plus;
	int			hash;
	int			zero;
}				t_flag;

typedef struct	s_format
{
	int			width;
	int			precision;
	t_flag		*flag;
	char		specifier;
	char		length;
	void		*value;
	t_type		type;
}				t_format;

int			parse_input(t_list **lst, char *string);
void		error(int i);
t_format	*init_format(void);

void	print_format(t_format *format);
void	handle_content(va_list ap, t_list *lst);
char	*handle_integer(t_format *f, int value);
