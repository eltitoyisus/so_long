/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_playable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:48:36 by jramos-a          #+#    #+#             */
/*   Updated: 2025/03/09 18:48:36 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int is_playable(t_map *map)
{
    if (!map || !map->map || !map->map[0])
    {
        printf("Invalid map structure\n");
        return (0);
    }

    printf("Checking map extension...\n");
    if (!check_extension(map->map[0]))
    {
        printf("Invalid map extension\n");
        return (0);
    }

    printf("Checking map file...\n");
    if (!check_file(map->map[0]))
    {
        printf("Invalid map file\n");
        return (0);
    }

    printf("Checking arguments...\n");
    if (!check_args(2, map->map))
    {
        printf("Invalid arguments\n");
        return (0);
    }

    printf("Checking valid path...\n");
    if (!check_valid_path(map))
    {
        printf("Invalid path in map\n");
        return (0);
    }

    return (1);
}
