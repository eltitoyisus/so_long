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
		$(SRC_DIR)map_parse.c	\
		$(SRC_DIR)convert_image.c \
		$(SRC_DIR)draw_map.c \
		$(SRC_DIR)end_map.c \
		$(SRC_DIR)error.c \
		$(SRC_DIR)generate_game.c \
		$(SRC_DIR)init_map.c \
		$(SRC_DIR)keys.c \
		$(SRC_DIR)validate_name.c

OBJS = $(SRCS:.c=.o)

libft/libft.a:
	@$(LIBFT_MAKE)
minilibx/libmlx.a:
	@$(MLX_MAKE)

$(NAME): $(OBJS) libft/libft.a minilibx/libmlx.a
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a minilibx/libmlx.a $(MLXFLAGS) -o $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJS) 
	@ cd libft && make clean > /dev/null
	@ cd minilibx && make clean > /dev/null

fclean: clean
	@$(RM) $(NAME)
	@ cd libft && make fclean > /dev/null

re: fclean all
