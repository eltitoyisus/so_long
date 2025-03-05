/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:33:48 by jramos-a          #+#    #+#             */
/*   Updated: 2025/01/30 13:33:48 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	t_game	game;

	if (argc == 2)
	{
		map_initializer(&map, argv);
		map_checker(&map);
		game.mlx = mlx_init();
		game.win = mlx_new_window(game.mlx, map.player_x * IMG_PXL, map.player_y * IMG_PXL, WND_NAME);
		file_to_image(&map);
		map_printer(&map);
		mlx_hook(game.win, 17, 0, ft_close_map, &map);
		mlx_key_hook(game.win, key_hook, &map);
		mlx_loop(game.mlx);
	}
	exit(EXIT_FAILURE);
}
