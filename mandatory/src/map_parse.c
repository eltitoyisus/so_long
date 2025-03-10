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

void move_on_paths(int x, int y, t_map *map)
{
    char type;

    if (x < 0 || y < 0 || x >= map->cols || y >= map->rows)
        return;
        
    type = map->copy[y][x];
    
    // If it's a wall or already visited cell, return
    if (type == '1')
        return;
        
    // Process current cell
    if (type == 'C')
        map->c_check--;
    else if (type == 'E')
        map->e_check = 0; // Mark that we found the exit
        
    // Mark as visited
    map->copy[y][x] = '1';
    
    // Explore all 4 directions
    move_on_paths(x + 1, y, map);
    move_on_paths(x - 1, y, map);
    move_on_paths(x, y + 1, map);
    move_on_paths(x, y - 1, map);
}

int check_valid_path(t_map *map)
{
    int i;

    // Make sure we've counted the collectibles and found the exit first
    printf("Collectibles: %d, Exit check: %d\n", map->c, map->e);
    
    // Initialize properly
    map->c_check = map->c;
    map->e_check = 1;  // We expect to find exactly one exit
    
    // Find player position
    find_player(map);
    printf("Player position: (%d, %d)\n", map->player_x, map->player_y);
    
    // Create a copy of the map for path finding
    map->copy = copy_map(map->map, map->rows);
    if (!map->copy)
    {
        printf("Error: COULDN'T LOAD MAP\n");
        return (1); 
    }
    
    // Fill all reachable positions
    move_on_paths(map->player_x, map->player_y, map);
    printf("After path checking - C_check: %d, E_check: %d\n", map->c_check, map->e_check);
    
    // Check if we found all collectibles and the exit
    if (map->c_check != 0 || map->e_check != 0)
    {
        printf("NOT A VALID MAP - Not all collectibles or exit are reachable\n");
        for (i = 0; i < map->rows; i++)
            free(map->copy[i]);
        free(map->copy);
        return (1);
    }
    
    // Free the copy
    for (i = 0; i < map->rows; i++)
        free(map->copy[i]);
    free(map->copy);
    return (0);
}	

int ft_parse_map(int argc, char **argv, t_map *map)
{
    printf("Parsing map with argc: %d, argv[1]: %s\n", argc, argv[1]);
    
    // Check basic file validity first
    if (!check_extension(argv[1]))
    {
        printf("Invalid file extension\n");
        return (1);
    }
    
    // Load map data from the file
    if (!load_map_from_file(argv[1], map))
    {
        printf("Failed to load map from file\n");
        return (1);
    }
    
    // Now that the map is loaded, check path validity
    if (check_valid_path(map) != 0)  // Note: returns 0 for valid path
    {
        printf("Invalid path in map\n");
        return (1);
    }
    
    printf("Map parsed successfully\n");
    return (0);
}

int load_map_from_file(char *filename, t_map *map)
{
    int fd;
    char *line;
    int row;
    
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (0);
    
    // First count rows and find max column width
    row = 0;
    map->cols = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        int line_len = ft_strlen(line);
        if (line[line_len - 1] == '\n')
            line_len--; // Adjust for newline
        map->cols = map->cols > line_len ? map->cols : line_len;
        free(line);
        row++;
    }
    map->rows = row;
    
    if (map->rows == 0 || map->cols == 0)
    {
        printf("Error: Map is empty or invalid\n");
        return (0);
    }
    
    // Allocate map memory
    map->map = (char **)malloc(sizeof(char *) * map->rows);
    if (!map->map)
        return (0);
    
    // Reopen file and fill the map
    close(fd);
    fd = open(filename, O_RDONLY);
    row = 0;
    map->c = 0;  // Initialize collectible count
    map->e = 0;  // Initialize exit count
    map->p = 0;  // Track player count
    
    while (row < map->rows && (line = get_next_line(fd)) != NULL)
    {
        map->map[row] = ft_strdup(line);
        // Count elements in the map
        for (int i = 0; line[i] && line[i] != '\n'; i++)
        {
            if (line[i] == 'C')
                map->c++;
            else if (line[i] == 'E')
                map->e++;
            else if (line[i] == 'P')
                map->p++;
        }
        free(line);
        row++;
    }
    close(fd);
    
    printf("Map loaded: %d rows, %d cols, %d collectibles, %d exits, %d players\n", 
           map->rows, map->cols, map->c, map->e, map->p);
    
    return (1);
}
