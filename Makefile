# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 09:06:43 by relgheit          #+#    #+#              #
#    Updated: 2025/02/25 12:49:21 by relgheit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES= main.c

OFILES= $(CFILES:.c=.o)

CC= cc

LIBMLX= ./MLX42

HEADERS= -I $(LIBMLX)/include 
CFLAGS= -Wall -Werror -Wextra -Wunreachable-code -Ofast

LIBS= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

NAME= fdf

all: libmlx $(NAME)

libmlx:
		@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
%.o: %.C
		@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OFILES)
		@$(CC) $(OFILES) $(LIBS) $(HEADERS) -o $(NAME)

clean:
		@rm -rf $(OFILES)
		@rm -rf $(LIBMLX)/build

fclean: clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx
