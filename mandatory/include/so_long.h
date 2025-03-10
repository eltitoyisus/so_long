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
# include "../../minilibx/mlx.h"
# include "../../minilibx/mlx_int.h"
# include <stdbool.h>
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
# define IMG_PXL 50
# define WND_NAME "so_long"

typedef struct s_map
{
    char    **map;
    char    **copy;
    int     rows;
    int     cols;
    int     c;
    int     e;
    int     p;      // Add this line to track player count
    int     c_check;
    int     e_check;
    int     player_x;
    int     player_y;
}   t_map;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_image
{
    void    *img;
    void    *empty;
    void    *wall;
    void    *exit;
    void    *collect;
    void    *player;
    int     width;
    int     height;
}   t_image;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_image		image;
	t_player	player;
}	t_game;

// MAP PARSE
char	**copy_map(char **map, int rows);
void	find_player(t_map *map);
void	move_on_paths(int x, int y, t_map *map);
int		check_valid_path(t_map *map);
int		ft_parse_map(int argc, char **argv, t_map *map);

// KEYS
int		key_hook(int keycode, t_game *game);

// MOVEMENT
void	move_a(t_map *map);
void	move_s(t_map *map);
void	move_d(t_map *map);
void	move_w(t_map *map);

// INIT MAP
void	init_game(t_game *game);
void	init_map(t_map *map);
void	init_player(t_player *player);
void	init_img(t_game *game);

// DRAW MAP
void	draw_map(t_game *game);
void	draw_player(t_game *game);
void	draw_collect(t_game *game);
void	draw_exit(t_game *game);
void	draw_background(t_game *game);
void	draw_game(t_game *game);
void	draw_wall(t_game *game);

// END MAP
int		ft_close_map(t_game *game);

// ERROR AND FREE
void	ft_free_map(t_map *map);
void	ft_free_game(t_game *game);

// MAP NAME PARSE

int		check_extension(char *filename);
int		check_args(int argc, char **argv);
int		check_file(char *file);

// IS PLAYABLE
int		is_playable(t_map *map);
int load_map_from_file(char *filename, t_map *map);
int ft_max(int a, int b);


#endif
