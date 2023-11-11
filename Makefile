# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paboutel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 16:57:59 by paboutel          #+#    #+#              #
#    Updated: 2021/10/18 17:53:44 by paboutel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

FLAGS = -Wall -Wextra -Werror

SRC = ./src/mandatory/*/*.c
INCLUDES = -I ./include -I ./ft_printf
LIB_DIR = ./ft_printf/
LIB = $(addprefix $(LIB_DIR),libftprintf.a)

NAME = push_swap

all :
	make -C ./ft_printf
	make $(NAME)

$(NAME) :
	@$(CC) $(FLAGS) $(INCLUDES) -o $(NAME) $(SRC) $(LIB)
	@echo "compiling $(SRC) to $(NAME)"

clean :
	make clean -C $(LIB_DIR)
	@rm -f $(NAME)
	@echo "removing ${NAME}"

fclean : clean
	make fclean -C $(LIB_DIR)

re : clean all

.PHONY: re clean all
