# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 13:53:41 by jramos-a          #+#    #+#              #
#    Updated: 2025/01/30 13:53:41 by jramos-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
RM = rm -rf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = $(SRCS:.c=.o)

SRCS = src/main.c        \
		src/movement.c   \
		src/map_parse.c

all: $(NAME)
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
