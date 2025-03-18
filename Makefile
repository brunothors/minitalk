# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bnespoli <bnespoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/29 18:13:20 by bnespoli          #+#    #+#              #
#    Updated: 2024/09/10 01:56:45 by bnespoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_MC 	= client
NAME_MS 	= server

CC			= cc
CFLAGS		= -Werror -Wall -Wextra -g3
LIBFT		= ./libft/libft.a

M_INC		= -I src/minitalk.h

PATH_M		=	src/
CLIENT_M	=	$(addprefix $(PATH_M), client.c)
SERVER_M	=	$(addprefix $(PATH_M), server.c)

CLIENT_M_O	=	$(CLIENT_M:%.c=%.o)
SERVER_M_O	=	$(SERVER_M:%.c=%.o)

BLUE 		= \033[1;36m
WHITE 		= \033[0;39m
T_LIB		= $(shell test -f ./libft/get_next_line_utils.o && echo "yes" 2>&1)

all: libft $(NAME_MC) $(NAME_MS)

libft:
	@if ! [ $(T_LIB) ]; then echo "$(BLUE)-*- Creating libft library. -*-$(WHITE)";fi
	@make -C ./libft --no-print-directory

$(NAME_MC): $(CLIENT_M_O)
	$(CC) $(CFLAGS) $< -I $(PATH_M) $(LIBFT) -o $@

$(NAME_MS): $(SERVER_M_O)
	$(CC) $(CFLAGS) $< -I $(PATH_M) $(LIBFT) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C ./libft --no-print-directory
	rm -f $(CLIENT_M_O) $(SERVER_M_O)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME_MC) $(NAME_MS)

re: fclean all

.PHONY: all clean fclean re libft