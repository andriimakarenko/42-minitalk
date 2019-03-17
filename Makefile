# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pkuznets <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/17 19:28:20 by pkuznets          #+#    #+#              #
#    Updated: 2019/03/17 19:28:31 by pkuznets         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER   = server
CLIENT   = client
CC	     = gcc
FLAGS    = -Wall -Werror -Wextra
LIBS	 = -L./libft -lft
LIBFT	 = libft.a

all : $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT) :
	@make -C libft

$(SERVER) : ./server_src/server.c  minitalk.h
	@$(CC) ./server_src/server.c $(LIBS) -o $@

$(CLIENT) : ./client_src/client.c minitalk.h
	@$(CC) ./client_src/client.c $(LIBS) -o $@

%.o : %.c
	@$(CC) $(FLAGS) $< -c -I minitalk.h

clean :
	@make clean -C libft
	@rm -f *.o

fclean: clean
	@make fclean -C libft
	@rm -f $(SERVER) $(CLIENT)

re: fclean all