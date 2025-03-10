/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:33:50 by jramos-a          #+#    #+#             */
/*   Updated: 2025/03/02 12:33:50 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	init_map(&game->map);
	init_player(&game->player);
	init_img(game);
}

void init_map(t_map *map)
{
    map->rows = 0;
    map->cols = 0;
    map->c = 0;
    map->e = 0;
    map->p = 0;  // Initialize the new player count
    map->c_check = 0;
    map->e_check = 0;
    map->player_x = 0;
    map->player_y = 0;
}

void	init_player(t_player *player)
{
	player->x = 0;
	player->y = 0;
}

void	init_img(t_game *game)
{
	game->image.img = mlx_xpm_file_to_image(game->mlx, "xmp/ground.xpm", &game->image.width, &game->image.height);
	game->image.collect = mlx_xpm_file_to_image(game->mlx, "xmp/collect.xpm", &game->image.width, &game->image.height);
	game->image.exit = mlx_xpm_file_to_image(game->mlx, "xmp/door.xpm", &game->image.width, &game->image.height);
	game->image.player = mlx_xpm_file_to_image(game->mlx, "xmp/player.xpm", &game->image.width, &game->image.height);
	game->image.wall = mlx_xpm_file_to_image(game->mlx, "xmp/wall.xpm", &game->image.width, &game->image.height);
}
