/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lloison < lloison@student.42mulhouse.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:27:33 by lloison           #+#    #+#             */
/*   Updated: 2023/02/13 15:47:18 by lloison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_borders(t_map *map)
{
	int	x;

	x = -1;
	while (++x < map->max_x_size)
		if ((map->map_arr[0][x] != ' ' && map->map_arr[0][x] != '1')
			|| (map->map_arr[map->max_y_size - 1][x] != ' '
				&& map->map_arr[map->max_y_size - 1][x] != '1'))
			parsing_error("Map is not enclosed");
	x = -1;
	while (++x < map->max_y_size)
		if ((map->map_arr[x][0] != ' ' && map->map_arr[x][0] != '1')
			|| (map->map_arr[x][map->max_x_size - 1] != ' '
				&& map->map_arr[x][map->max_x_size - 1] != '1'))
			parsing_error("Map is not enclosed");
}

static void	check_adjacent(t_map *map, int x, int y)
{
	if (y != 0)
		if (map->map_arr[y - 1][x] != ' ' && map->map_arr[y - 1][x] != '1')
			parsing_error("Map is not enclosed");
	if (y < map->max_y_size - 1)
		if (map->map_arr[y + 1][x] != ' ' && map->map_arr[y + 1][x] != '1')
			parsing_error("Map is not enclosed");
	if (x != 0)
		if (map->map_arr[y][x - 1] != ' ' && map->map_arr[y][x - 1] != '1')
			parsing_error("Map is not enclosed");
	if (x < map->max_x_size - 1)
		if (map->map_arr[y][x + 1] != ' ' && map->map_arr[y][x + 1] != '1')
			parsing_error("Map is not enclosed");
}

static void	check_spaces(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->max_y_size)
	{
		x = 0;
		while (x < map->max_x_size)
		{
			if (map->map_arr[y][x] == ' ')
				check_adjacent(map, x, y);
			x++;
		}
		y++;
	}
}

void	check_map(t_map *map)
{
	check_borders(map);
	check_spaces(map);
}