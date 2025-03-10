/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:33:25 by jramos-a          #+#    #+#             */
/*   Updated: 2025/03/02 12:33:25 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int ft_close_map(t_game *game)
{
	ft_putstr_fd("Closing game\n", 1);
	free_game(game);
	ft_free_map(&game->map);
	exit(0);
	return (0);
}
