
#include "../include/so_long.h"

int key_hook(int keycode, t_map *map)
{
	find_player(map);
	if (keycode == KEY_ESC)
		return(ft_close_map(map));
	else if (map->exit == 1)
		return (0);
	else if (keycode == KEY_A)
		move_a(map);
	else if (keycode == KEY_S)
		move_s(map);
	else if (keycode == KEY_D)
		move_d(map);
	else if (keycode == KEY_W)
		move_w(map);
	return (0);
}