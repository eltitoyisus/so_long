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

void	draw_map(t_game *game)
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
				mlx_put_image_to_window(game->mlx, game->win, game->img.wall, x * 32, y * 32);
			else if (game->map.map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->img.img, x * 32, y * 32);
			else if (game->map.map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->img.collectible, x * 32, y * 32);
			else if (game->map.map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->img.exit, x * 32, y * 32);
			else if (game->map.map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->img.player, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	draw_game(t_game *game)
{
	draw_background(game);
	draw_map(game);
	draw_player(game);
	draw_collectibles(game);
	draw_exit(game);
}
