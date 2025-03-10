/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 19:28:47 by jramos-a          #+#    #+#             */
/*   Updated: 2025/03/10 19:28:47 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	load_map_content(char *filename, t_map *map)
{
	if (!initialize_map_memory(map))
		return (0);
	if (!read_map_from_file(filename, map))
		return (0);
	return (1);
}
