# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadamant <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/09 06:18:48 by sadamant          #+#    #+#              #
#    Updated: 2018/07/12 19:39:04 by sadamant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDES = includes/

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	  ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
	  ft_lstiter.c ft_lstnew.c ft_lstmap.c ft_memalloc.c ft_memccpy.c ft_memchr.c \
	  ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c\
	  ft_putchar.c ft_wordcount.c ft_strcsplit.c\
	  ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c \
	  ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strclr.c \
	  ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c \
	  ft_striteri.c ft_strjoin.c ft_strlen.c ft_strlcat.c ft_strmap.c ft_strmapi.c \
	  ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strfill.c\
	  ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
	  ft_numlen.c ft_numlen_base.c ft_lstappend.c ft_numlen_abs.c\
	  ft_strtolower.c\
	  ft_tolower.c ft_toupper.c ft_pow.c ft_atof.c ft_itoa_abs.c ft_itoa_base.c\
	  ft_arrlen.c ft_strendsw.c ft_ishexa.c ft_freedarray.c\
	  vsub.c vadd.c vmag.c vdot.c v3new.c vnorm.c\
	  ft_rgb.c\
	  ft_uitoa.c ft_uitoa_base.c ft_unumlen.c ft_unumlen_base.c\
	  matnew.c \
	  get_next_line.c

OBJ = $(SRC:.c=.o)

CC = gcc
FLAGS = -c -Wall -Werror -Wextra

all: $(NAME)

$(OBJ): $(SRC)
	@$(CC) $(FLAGS) $(SRC) -I $(INCLUDES)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
