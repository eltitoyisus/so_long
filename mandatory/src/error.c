/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:33:45 by jramos-a          #+#    #+#             */
/*   Updated: 2025/03/02 12:33:45 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void ft_free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->rows)
	{
		free(map->map[i]);
		free(map->copy[i]);
		i++;
	}
	free(map->map);
	free(map->copy);
}

void	ft_free_game(t_game *game)
{
	ft_free_map(&game->map);
	free(game->image.img);
	free(game->image.collect);
	free(game->image.exit);
	free(game->image.player);
	free(game->image.wall);
	free(game->mlx);
	free(game->win);
}

void ft_free_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
