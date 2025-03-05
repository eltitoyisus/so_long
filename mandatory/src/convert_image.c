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

void	xmp_convert(t_map *map)
{
	int	a;

	a = IMG_PXL;
	map->img.empty = mlx_xpm_file_to_image(map->mlx,
			"../xmp/empty.xpm", &a, &a);
	map->img.wall = mlx_xpm_file_to_image(map->mlx,
			"../xmp//wall.xpm", &a, &a);
	map->img.exit = mlx_xpm_file_to_image(map->mlx,
			"../xmp/door.xpm", &a, &a);
	map->img.collect = mlx_xpm_file_to_image(map->mlx,
			"../xmp/collect.xpm", &a, &a);
	map->img.player = mlx_xpm_file_to_image(map->mlx,
				"../xmp/player.xpm", &a, &a);
}
