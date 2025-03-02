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

void	move_a(t_map *map)
{
	if (map->map[map->player_y][map->player_x - 1] == 'E')
	{
		map->map[map->player_y][map->player_x] = '0';
		map->map[map->player_y][map->player_x - 1] = 'P';
		map->player_x--;
		map->e_check++;
	}
	else if (map->map[map->player_y][map->player_x - 1] == '0')
	{
		map->map[map->player_y][map->player_x] = '0';
		map->map[map->player_y][map->player_x - 1] = 'P';
		map->player_x--;
	}
}

void	move_s(t_map *map)
{
	if (map->map[map->player_y + 1][map->player_x] == 'E')
	{
		map->map[map->player_y][map->player_x] = '0';
		map->map[map->player_y + 1][map->player_x] = 'P';
		map->player_y++;
		map->e_check++;
	}
	else if (map->map[map->player_y + 1][map->player_x] == '0')
	{
		map->map[map->player_y][map->player_x] = '0';
		map->map[map->player_y + 1][map->player_x] = 'P';
		map->player_y++;
	}
}

void	move_d(t_map *map)
{
	if (map->map[map->player_y][map->player_x + 1] == 'E')
	{
		map->map[map->player_y][map->player_x] = '0';
		map->map[map->player_y][map->player_x + 1] = 'P';
		map->player_x++;
		map->e_check++;
	}
	else if (map->map[map->player_y][map->player_x + 1] == '0')
	{
		map->map[map->player_y][map->player_x] = '0';
		map->map[map->player_y][map->player_x + 1] = 'P';
		map->player_x++;
	}
}

void	move_w(t_map *map)
{
	if (map->map[map->player_y - 1][map->player_x] == 'E')
	{
		map->map[map->player_y][map->player_x] = '0';
		map->map[map->player_y - 1][map->player_x] = 'P';
		map->player_y--;
		map->e_check++;
	}
	else if (map->map[map->player_y - 1][map->player_x] == '0')
	{
		map->map[map->player_y][map->player_x] = '0';
		map->map[map->player_y - 1][map->player_x] = 'P';
		map->player_y--;
	}
}
