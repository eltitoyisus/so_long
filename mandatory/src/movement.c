/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:35:22 by jramos-a          #+#    #+#             */
/*   Updated: 2025/01/30 13:35:22 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_a(t_game *game)
{
    if (game->map.map[game->map.player_y][game->map.player_x - 1] == 'E')
    {
        game->map.map[game->map.player_y][game->map.player_x] = '0';
        game->map.map[game->map.player_y][game->map.player_x - 1] = 'P';
        game->map.player_x--;
        game->map.e_check++;
    }
    else if (game->map.map[game->map.player_y][game->map.player_x - 1] == '0' 
        || game->map.map[game->map.player_y][game->map.player_x - 1] == 'C')
    {
        // If moving to a collectible, increment counter or handle as needed
        if (game->map.map[game->map.player_y][game->map.player_x - 1] == 'C')
            game->map.c--;

        game->map.map[game->map.player_y][game->map.player_x] = '0';
        game->map.map[game->map.player_y][game->map.player_x - 1] = 'P';
        game->map.player_x--;
    }
    // Update player position in the game struct
    game->player.x = game->map.player_x;
    game->player.y = game->map.player_y;
    draw_game(game);
}

void	move_s(t_game *game)
{
    if (game->map.map[game->map.player_y + 1][game->map.player_x] == 'E')
    {
        game->map.map[game->map.player_y][game->map.player_x] = '0';
        game->map.map[game->map.player_y + 1][game->map.player_x] = 'P';
        game->map.player_y++;
        game->map.e_check++;
    }
    else if (game->map.map[game->map.player_y + 1][game->map.player_x] == '0'
        || game->map.map[game->map.player_y + 1][game->map.player_x] == 'C')
    {
        // If moving to a collectible, increment counter or handle as needed
        if (game->map.map[game->map.player_y + 1][game->map.player_x] == 'C')
            game->map.c--;

        game->map.map[game->map.player_y][game->map.player_x] = '0';
        game->map.map[game->map.player_y + 1][game->map.player_x] = 'P';
        game->map.player_y++;
    }
    // Update player position in the game struct
    game->player.x = game->map.player_x;
    game->player.y = game->map.player_y;
    draw_game(game);
}

void	move_d(t_game *game)
{
    if (game->map.map[game->map.player_y][game->map.player_x + 1] == 'E')
    {
        game->map.map[game->map.player_y][game->map.player_x] = '0';
        game->map.map[game->map.player_y][game->map.player_x + 1] = 'P';
        game->map.player_x++;
        game->map.e_check++;
    }
    else if (game->map.map[game->map.player_y][game->map.player_x + 1] == '0'
        || game->map.map[game->map.player_y][game->map.player_x + 1] == 'C')
    {
        // If moving to a collectible, increment counter or handle as needed
        if (game->map.map[game->map.player_y][game->map.player_x + 1] == 'C')
            game->map.c--;

        game->map.map[game->map.player_y][game->map.player_x] = '0';
        game->map.map[game->map.player_y][game->map.player_x + 1] = 'P';
        game->map.player_x++;
    }
    // Update player position in the game struct
    game->player.x = game->map.player_x;
    game->player.y = game->map.player_y;
    draw_game(game);
}

void	move_w(t_game *game)
{
    if (game->map.map[game->map.player_y - 1][game->map.player_x] == 'E')
    {
        game->map.map[game->map.player_y][game->map.player_x] = '0';
        game->map.map[game->map.player_y - 1][game->map.player_x] = 'P';
        game->map.player_y--;
        game->map.e_check++;
    }
    else if (game->map.map[game->map.player_y - 1][game->map.player_x] == '0'
        || game->map.map[game->map.player_y - 1][game->map.player_x] == 'C')
    {
        // If moving to a collectible, increment counter or handle as needed
        if (game->map.map[game->map.player_y - 1][game->map.player_x] == 'C')
            game->map.c--;

        game->map.map[game->map.player_y][game->map.player_x] = '0';
        game->map.map[game->map.player_y - 1][game->map.player_x] = 'P';
        game->map.player_y--;
    }
    // Update player position in the game struct
    game->player.x = game->map.player_x;
    game->player.y = game->map.player_y;
    draw_game(game);
}
