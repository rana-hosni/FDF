# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 09:11:57 by relgheit          #+#    #+#              #
#    Updated: 2024/10/08 09:23:11 by relgheit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#variable for c files
# CFILES = ft_isalpha.c ft_isdigit.c ft_isascii.c ft_memcpy.c\
# ft_bzero.c
CFILES = ft_isalpha.c ft_isdigit.c ft_isascii.c ft_bzero.c\
ft_calloc.c ft_isalnum.c ft_isprint.c ft_memchr.c ft_memcmp.c\
ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strrchr.c\
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c\
ft_tolower.c ft_toupper.c ft_atoi.c ft_strdup.c ft_strjoin.c\
ft_substr.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c\
ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_strnstr.c ft_strmapi.c\
ft_striteri.c ft_split.c
CBFILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
ft_lstdelone.c ft_lstclear.c 
#variable for .o files
OFILES = $(CFILES:.c=.o)
BFILES = $(CBFILES:.c=.o)
#the header
# HEADER = libft.h
#the cc compile
CC = cc
#the flags
CFLAGS = -Wall -Wextra -Werror
#Name of the output
NAME = libft.a
.PHONY: all clean fclean re bonus
all: $(NAME)
#$(CC) $(CFLAGS) -c ft_isalpha.c -o ft_isalpha.o
#Builds the static library by archiving .o files
$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES) 
bonus: $(BFILES)
	ar rcs $(NAME) $(OFILES) $(BFILES)
#Handles all .c files into .o files
# %.o: %.c $(HEADER)
# 	$(CC) $(CFLAGS) -c $< -o $@
#removes all .o files
clean:
	rm -f $(OFILES)
fclean: clean
	rm -f $(NAME)
re: fclean all
