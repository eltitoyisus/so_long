/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:35:27 by jramos-a          #+#    #+#             */
/*   Updated: 2025/01/30 13:35:27 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**copy_map(char **map, int rows)
{
	char	**new_map;
	int		i;

	new_map = (char **)malloc(sizeof(char *) * rows);
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			while (--i >= 0)
				free(new_map[i]);
			free(new_map);
			return (NULL);
		}
		i++;
	}
	return (new_map);
}

void	find_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->map[i][j] == 'P')
			{
				map->player_x = j;
				map->player_y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	move_on_paths(int x, int y, t_map *map)
{
	char	type;

	if (x < 0 || y < 0 || x >= map->cols || y >= map->rows)
		return ;
	type = map->copy[y][x];
	if (type == 'C')
	{
		map->c_check -= 1;
		map->copy[y][x] = '1';
	}
	else if (type == 'E')
	{
		map->e_check -= 1;
		map->copy[y][x] = '1';
	}
	else if (type == '0' || type == 'P')
		map->copy[y][x] = '1';
	else
		return ;
	move_on_paths(x + 1, y, map);
	move_on_paths(x - 1, y, map);
	move_on_paths(x, y + 1, map);
	move_on_paths(x, y - 1, map);
}

int check_valid_path(t_map *map)
{
    int i;

    map->c_check = map->c;
    map->e_check = map->e;
    find_player(map);
    map->copy = copy_map(map->map, map->rows);
    if (!map->copy)
    {
        printf("Error: COULDN'T LOAD MAP\n");
        return (1);
    }
    move_on_paths(map->player_x, map->player_y, map);
    if (map->c_check != 0 || map->e_check >= map->e)
    {
        printf("NOT A VALID MAP\n");
        for (i = 0; i < map->rows; i++)
            free(map->copy[i]);
        free(map->copy);
        return (1);
    }
    i = 0;
    while (i < map->rows)
    {
        free(map->copy[i]);
        i++;
    }
    free(map->copy);
    return (0);
}

int ft_parse_map(int argc, char **argv, t_map *map)
{
    printf("Parsing map with argc: %d, argv[1]: %s\n", argc, argv[1]);
    if (!check_extension(argv[1]))
	{
		printf("Invalid file extension\n");
		return (1);
	}
    if (!check_file(argv[1]))
    {
        printf("Invalid map file\n");
        return (1);
    }
    if (!check_args(argc, argv))
    {
        printf("Invalid arguments\n");
        return (1);
    }
    if (!check_valid_path(map))
    {
        printf("Invalid path in map\n");
        return (1);
    }
    printf("Map parsed successfully\n");
    return (0);
}
