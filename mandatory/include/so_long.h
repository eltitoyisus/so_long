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
# define WND_NAME "so_long"

typedef struct s_map
{
	char	**map;
	char	**copy;
	int		rows;
	int		cols;
	int		c;
	int		e;
	int		c_check;
	int		e_check;
	int		player_x;
	int		player_y;
}	t_map;

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
