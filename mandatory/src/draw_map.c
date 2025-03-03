/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:56:08 by jramos-a          #+#    #+#             */
/*   Updated: 2025/03/03 10:56:08 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win, game->img.player, game->player.x * 32, game->player.y * 32);
}

void	draw_collectibles(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			if (game->map.map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img.collectible, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	draw_exit(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			if (game->map.map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img.exit, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	draw_images(t_game *game)
{
	game->img.img = mlx_xpm_file_to_image(game->mlx, "textures/ground.xpm", &game->img.width, &game->img.height);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx, "textures/collectible.xpm", &game->img.width, &game->img.height);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &game->img.width, &game->img.height);
	game->img.player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &game->img.width, &game->img.height);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &game->img.width, &game->img.height);
}

void	draw_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img.img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}
