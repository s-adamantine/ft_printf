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
# include <limits.h>

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
	int			space;
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
	int			charswritten;
}				t_format;

typedef struct	s_printf
{
	int			charcount;
}				t_printf;

int			parse_input(va_list ap, char *string, int *charswritten);
void		error(int i);
void		put_error(char *str);
void		error_undefined(char flag, char specifier);
t_format	*init_format(void);

void	print_format(t_format *format);
char	*handle_content(va_list ap, t_format *format);
char	*handle_integer(t_format *f, intmax_t value);
char	*handle_unsignedint(t_format *f, uintmax_t value);
char	*handle_string(t_format *f, char *str);
char	*handle_upperhexa(t_format *f, uintmax_t value);
char	*handle_character(t_format *f, unsigned int c);
char	*handle_octal(t_format *f, uintmax_t value);
char	*handle_percent(t_format *f);
char	*precision_overfill(t_format *f, int numlen);
