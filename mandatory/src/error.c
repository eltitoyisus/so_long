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

void	ft_free_map(t_map *map)
{
	int i;
	
	i = 0;
	if (map && map->map)
	{
		while (i < map->rows && map->map[i])
		{
			free(map->map[i]);
			map->map[i] = NULL;
			i++;
		}
		free(map->map);
		map->map = NULL;
	}
}

void	destroy_img(void *mlx, void *img)
{
	if (mlx && img)
	{
		mlx_destroy_image(mlx, img);
		img = NULL;
	}
}

static	void destroy_all_images(void *mlx, t_image *image)
{
	if (mlx && image)
	{
		destroy_img(mlx, image->img);
		destroy_img(mlx, image->empty);
		destroy_img(mlx, image->wall);
		destroy_img(mlx, image->exit);
		destroy_img(mlx, image->collect);
		destroy_img(mlx, image->player);
	}
}

static	void destroy_mlx_resources(void *mlx, void *win)
{
	if (mlx)
	{
		if (win)
			mlx_destroy_window(mlx, win);
		mlx_destroy_display(mlx);
		free(mlx);
	}
}

void	free_img(void *mlx, t_image *image)
{
	if (!mlx || !image)
		return ;
	destroy_all_images(mlx, image);
}

void free_game(t_game *game)
{
	if (!game)
		return ;
	if (game->mlx)
	{
		free_img(game->mlx, &game->image);
		destroy_mlx_resources(game->mlx, game->win);
	}
}
