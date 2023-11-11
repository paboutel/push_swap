# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: paboutel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 16:57:42 by paboutel          #+#    #+#              #
#    Updated: 2021/10/18 16:57:44 by paboutel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c utils.c address.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "creation of ${NAME}"
	@echo "generating index for ${NAME}"

%.o: %.c
			@$(CC) -o $@ -c $? $(FLAGS)
			@echo "compiling $? to $@"

clean:
	@rm -f $(OBJS)
	@echo "removing ${OBJS}"

fclean: clean
	@rm -f $(NAME)
	@echo "removing ${NAME}"

re: fclean all

.PHONY: fclean re norme all clean
