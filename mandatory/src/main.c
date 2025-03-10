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

int main(int argc, char **argv)
{
    t_game game;

    (void)argv;
    if (argc != 2)
    {
        ft_putstr_fd("Invalid arguments\n", 2);
        return (1);
    }
    printf("hola\n");
    if (ft_parse_map(argc, argv, &game.map) == 0)
    {
        printf("iniit game\n");
        init_game(&game);
        init_map(&game.map);
        printf("Map parsed\n");
        init_player(&game.player);
        printf("Player initialized\n");
        init_img(&game);
        printf("Images initialized\n");
    }
    else
    {
        ft_putstr_fd("Map is not playable\n", 2);
        return (1);
    }
    if (!(game.mlx = mlx_init()))
    {
        ft_putstr_fd("Failed to initialize mlx\n", 2);
        return (1);
    }

    if (!(game.win = mlx_new_window(game.mlx, game.map.cols * IMG_PXL, game.map.rows * IMG_PXL, "so_long")))
    {
        ft_putstr_fd("Failed to create window\n", 2);
        return (1);
    }

    printf("Setting up hooks\n");
    mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
    mlx_hook(game.win, 17, 1L << 17, ft_close_map, &game);
    printf("Entering mlx loop\n");
    mlx_loop(game.mlx);
    printf("Exiting mlx loop\n");

    return (0);
}
