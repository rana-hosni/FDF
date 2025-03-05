# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/25 09:06:43 by relgheit          #+#    #+#              #
#    Updated: 2025/03/05 13:34:53 by relgheit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFILES= main.c read_file.c

OFILES= $(CFILES:.c=.o)

CC= cc

LIBMLX= ./MLX42

HEADERS= -I $(LIBMLX)/include -I ./libft -I ./printf

CFLAGS= #-Wall -Werror -Wextra -Wunreachable-code -Ofast

LIBS= $(LIBMLX)/build/libmlx42.a ./libft/libft.a ./printf/libftprintf.a -ldl -lglfw -pthread -lm


NAME= fdf

all: libmlx $(NAME)

libmlx:
		@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
		make -C ./libft
		make -C ./printf
		
libs:
		make -C 
%.o: %.C
		@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OFILES)
		@$(CC) $(OFILES) $(LIBS) $(HEADERS) -o $(NAME)

clean:
		@rm -rf $(OFILES)
		@rm -rf $(LIBMLX)/build
		@rm -rf ./libft/*.o
		@rm -rf ./printf/*.o

fclean: clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx
