/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbengea <vbengea@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:56:08 by jramos-a          #+#    #+#             */
/*   Updated: 2025/03/10 12:05:31 by vbengea          ###   ########.fr       */
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

int draw_game(t_game *game)
{
	if (!game || !game->mlx || !game->win)
		return (1);
		
	draw_background(game);
	draw_map(game);
	draw_player(game);
	draw_collect(game);
	draw_exit(game);
	draw_wall(game);
	return (0);
}

void draw_wall(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.cols)
		{
			if (game->map.map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->image.wall, x * 32, y * 32);
			x++;
		}
		y++;
	}
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
