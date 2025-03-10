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
    
    // Initialize game structures
    init_game(&game);
    
    printf("Parsing map...\n");
    if (ft_parse_map(argc, argv, &game.map) == 0)
    {
        printf("Map dimensions: %d rows x %d cols\n", game.map.rows, game.map.cols);
        
        // Initialize player and images
        init_player(&game.player);
        init_img(&game);
        
        // Initialize MLX
        if (!(game.mlx = mlx_init()))
        {
            ft_putstr_fd("Failed to initialize mlx\n", 2);
            return (1);
        }
        
        // Create window with proper dimensions
        game.win = mlx_new_window(game.mlx, game.map.cols * IMG_PXL, 
                                  game.map.rows * IMG_PXL, WND_NAME);
        
        // Set up hooks and enter main loop
        mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
        mlx_hook(game.win, 17, 1L << 17, ft_close_map, &game);
        mlx_loop(game.mlx);
    }
    else
    {
        ft_putstr_fd("Map parsing failed\n", 2);
        return (1);
    }
    
    return (0);
}

int ft_max(int a, int b)
{
    return (a > b ? a : b);
}