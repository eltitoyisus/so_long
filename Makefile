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
SRC_DIR = mandatory/src/
LIBFT_MAKE = make -C /libft
MLX_MAKE = make -C /minilibx
LIBFT_A = /libft/libft.a
MLX_A = /minilibx/libmlx.a
CFLAGS = -Wall -Wextra -Werror -Ilibft -Iminilibx
MLXFLAGS = -lm -lX11 -lXext

SRCS = $(SRC_DIR)main.c        \
		$(SRC_DIR)movement.c   \
		$(SRC_DIR)map_parse.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MINILIBX) $(MLXFLAGS)

all: $(NAME)

clean:
	@$(RM) $(OBJS) 
	@ cd libft && make clean
	@ cd minilibx && make clean

fclean: clean
	@$(RM) $(NAME)

re: fclean all
