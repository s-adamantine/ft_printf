# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadamant <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/28 19:53:44 by sadamant          #+#    #+#              #
#    Updated: 2017/12/28 19:53:45 by sadamant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf
LIBNAME = libprintf.a
LIBS = -L. -lprintf -L libft/ -lft

SUBLIB_DIR = libft

SUBLIB = libft/libft.a

LIBNAME1 = libft.a
LIBNAME2 = libmlx.a

SRC = main.c parse.c testing_helpers.c\
	handle_content.c\
	handle_integer.c\

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
	@$(CC) $(LIBS) $(FRAMEWORK) -o $(NAME)

clean:
	@$(MAKE) clean -C $(SUBLIB_DIR)
	@rm -rf $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(SUBLIB_DIR)
	@rm -rf $(NAME)
	@rm -rf $(LIB)

re: fclean all

.PHONY: all libft clean fclean re
