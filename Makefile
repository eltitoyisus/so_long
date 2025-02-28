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
LIBFT_MAKE = make -C libft > /dev/null #redirect exit to /dev/null for no output
MLX_MAKE = make -C minilibx > /dev/null
CFLAGS = -Wall -Wextra -Werror -Ilibft -Iminilibx
MLXFLAGS = -lm -lX11 -lXext

SRCS = $(SRC_DIR)main.c        \
		$(SRC_DIR)movement.c   \
		$(SRC_DIR)map_parse.c

OBJS = $(SRCS:.c=.o)

libft/libft.a:
	@$(LIBFT_MAKE)
minilibx/libmlx.a:
	@$(MLX_MAKE)

$(NAME): $(OBJS) libft/libft.a minilibx/libmlx.a
	@$(CC) $(CFLAGS) $(OBJS)
	@libft/libft.a minilibx/libmlx.a
	@$(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJS) 
	@ cd libft && make clean > /dev/null
	@ cd minilibx && make clean > /dev/null

fclean: clean
	@$(RM) $(NAME)
	@ cd libft && make fclean > /dev/null

re: fclean all
