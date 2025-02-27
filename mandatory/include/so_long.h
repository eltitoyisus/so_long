/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:33:40 by jramos-a          #+#    #+#             */
/*   Updated: 2025/01/30 13:33:40 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../libft/libft.h"
# include "../../GNL/get_next_line.h"
# include "../../minilibx/mlx.h"
# include "../../minilibx/mlx_int.h"
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_img		img;
	t_player	player;
}	t_game;

#endif
