# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amakaren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/05 23:01:37 by amakaren          #+#    #+#              #
#    Updated: 2018/12/05 23:16:24 by amakaren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=clang

FLAGS=-Wall -Werror -Wextra -c

HEAD=-I.

SRC=ft_isdigit.c ft_putchar_fd.c ft_strdup.c ft_strnew.c ft_isprint.c \
	ft_putendl.c ft_strequ.c ft_strnstr.c ft_atoi.c ft_iswhitespace.c \
	ft_putendl_fd.c ft_striter.c ft_strrchr.c ft_bzero.c ft_itoa.c \
	ft_putnbr.c ft_striteri.c ft_strsplit.c ft_count_char_instances.c \
	ft_memalloc.c ft_putnbr_fd.c ft_strjoin.c ft_strstr.c \
	ft_count_delimiters.c ft_memccpy.c ft_putstr.c ft_strlcat.c ft_strsub.c \
	ft_count_end_ws.c ft_memchr.c ft_putstr_fd.c ft_strlen.c ft_strtrim.c \
	ft_count_start_ws.c ft_memcmp.c ft_strcat.c ft_strmap.c ft_tolower.c \
	ft_count_substrings.c ft_memcpy.c ft_strchr.c ft_strmapi.c ft_toupper.c \
	ft_get_sbstrlen.c ft_memdel.c ft_strclr.c ft_strncat.c ft_isalnum.c \
	ft_memmove.c ft_strcmp.c ft_strncmp.c ft_isalpha.c ft_memset.c \
	ft_strcpy.c ft_strncpy.c ft_isascii.c ft_putchar.c ft_strdel.c ft_strnequ.c\
	ft_lstadd.c ft_lstdelone.c ft_lstdel.c ft_lstnew.c ft_lstiter.c ft_lstmap.c\
	ft_strnotchr.c ft_stronlychr.c

OBJ=$(SRC:.c=.o)

$(NAME): libft.h
	$(CC) $(FLAGS) $(SRC) $(HEAD)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean
