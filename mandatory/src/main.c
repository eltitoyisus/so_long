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
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		return (1);
	}
	if (read_map(argv[1], &game.map) == -1)
	{
		ft_putstr_fd("Error\nInvalid map\n", 2);
		return (1);
	}
	game.mlx = mlx_init();
	if (!game.mlx)
	{
		ft_putstr_fd("Error\nmlx_init() failed\n", 2);
		return (1);
	}
	if (init_game(&game) == -1)
	{
		ft_putstr_fd("Error\ninit_game() failed\n", 2);
		return (1);
	}
	mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.win, 17, 1L << 17, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
