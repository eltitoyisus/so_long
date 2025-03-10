/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:33:36 by jramos-a          #+#    #+#             */
/*   Updated: 2025/03/02 12:33:36 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	xmp_convert(t_game *game)
{
	int	a;

	a = IMG_PXL;
	game->image.empty = mlx_xpm_file_to_image(game->mlx,
		"../xmp/empty.xpm", &a, &a);
	game->image.wall = mlx_xpm_file_to_image(game->mlx,
		"../xmp/wall.xpm", &a, &a);
	game->image.exit = mlx_xpm_file_to_image(game->mlx,
		"../xmp/door.xpm", &a, &a);
	game->image.collect = mlx_xpm_file_to_image(game->mlx,
		"../xmp/collect.xpm", &a, &a);
	game->image.player = mlx_xpm_file_to_image(game->mlx,
		"../xmp/player.xpm", &a, &a);
}
