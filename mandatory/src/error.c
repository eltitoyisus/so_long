
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
	free(game->img.img);
	free(game->img.collectible);
	free(game->img.exit);
	free(game->img.player);
	free(game->img.wall);
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
