# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadamant <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/28 19:53:44 by sadamant          #+#    #+#              #
#    Updated: 2018/07/12 18:38:36 by sadamant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf
LIBNAME = libftprintf.a
LIBS = -L. -lftprintf -L libft/ -lft

SUBLIB_DIR = libft

SUBLIB = libft/libft.a

LIBNAME1 = libft.a

SRC = printf.c parse.c testing_helpers.c\
	handle_content.c\
	handle_integer.c\
	handle_unsignedint.c\
	handle_string.c\
	handle_upperhexa.c\
	handle_octal.c\
	handle_character.c\
	handle_numtypes.c

OBJ = $(SRC:.c=.o)

CC = gcc
FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I libft/includes

all: $(NAME)

$(OBJ): $(SRC) printf.h
	$(CC) $(FLAGS) $(SRC) $(INCLUDES)

libft:
	@$(MAKE) -C $(SUBLIB_DIR)

$(NAME): libft $(OBJ)
	@ar -rc $(LIBNAME) $(OBJ)
	@$(CC) $(LIBS) -o $(NAME)

clean:
	@$(MAKE) clean -C $(SUBLIB_DIR)
	@rm -rf $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(SUBLIB_DIR)
	@rm -rf $(NAME)
	@rm -rf $(LIBNAME)

re: fclean all

.PHONY: all libft clean fclean re
