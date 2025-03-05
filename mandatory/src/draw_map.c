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
	mlx_put_image_to_window(game->mlx, game->win, game->image.player, game->player.x * 32, game->player.y * 32);
}

void	draw_collect(t_game *game)
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
				mlx_put_image_to_window(game->mlx, game->win, game->image.collect, x * 32, y * 32);
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
				mlx_put_image_to_window(game->mlx, game->win, game->image.exit, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	draw_images(t_game *game)
{
	game->image.img = mlx_xpm_file_to_image(game->mlx, "textures/ground.xpm", &game->image.width, &game->image.height);
	game->image.collect = mlx_xpm_file_to_image(game->mlx, "textures/collect.xpm", &game->image.width, &game->image.height);
	game->image.exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &game->image.width, &game->image.height);
	game->image.player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &game->image.width, &game->image.height);
	game->image.wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &game->image.width, &game->image.height);
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
			mlx_put_image_to_window(game->mlx, game->win, game->image.img, x * 32, y * 32);
			x++;
		}
		y++;
	}
}
