/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_name.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jramos-a <jramos-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 12:33:31 by jramos-a          #+#    #+#             */
/*   Updated: 2025/03/02 12:33:31 by jramos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 4] == '.' && file[len - 3] == 'b' && file[len - 2] == 'e' && file[len - 1] == 'r')
		return (1);
	return (0);
}

int	check_file(char *file)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	ret = get_next_line(fd, &line);
	while (ret > 0)
	{
		free(line);
		ret = get_next_line(fd, &line);
	}
	free(line);
	close(fd);
	if (ret < 0)
		return (0);
	return (1);
}

int	check_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\nInvalid number of arguments\n", 2);
		return (0);
	}
	if (!check_extension(argv[1]))
	{
		ft_putstr_fd("Error\nInvalid file extension\n", 2);
		return (0);
	}
	if (!check_file(argv[1]))
	{
		ft_putstr_fd("Error\nInvalid file\n", 2);
		return (0);
	}
	return (1);
}
