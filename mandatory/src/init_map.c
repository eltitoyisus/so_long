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
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->map.cols * 32, game->map.rows * 32, WND_NAME);
	game->player.x = 0;
	game->player.y = 0;
}

void	init_map(t_map *map)
{
	map->rows = 0;
	map->cols = 0;
	map->c = 0;
	map->e = 0;
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
	game->image.img = mlx_xpm_file_to_image(game->mlx, "textures/ground.xpm", &game->image.width, &game->image.height);
	game->image.collect = mlx_xpm_file_to_image(game->mlx, "textures/collectible.xpm", &game->image.width, &game->image.height);
	game->image.exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &game->image.width, &game->image.height);
	game->image.player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &game->image.width, &game->image.height);
	game->image.wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &game->image.width, &game->image.height);
}
