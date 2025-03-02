
#include "../include/so_long.h"

int ft_close_map(t_map *map)
{
	ft_free_map(map);
	ft_free_game(&map->game);
	exit(0);
	return (0);
}

