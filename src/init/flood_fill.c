/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:30:18 by tsomchan          #+#    #+#             */
/*   Updated: 2024/07/06 01:26:47 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	paint_and_count(char *c, t_map *map)
{
	if (iswalkable(*c) == 0)
		return (0);
	if (*c == 'C')
		map->n_collect += 1;
	else if (*c == 'E')
	{
		map->n_exit += 1;
		return (0);
	}
	*c = 'P';
	return (1);
}

void	paintnear(int y, int x, t_map *map)
{
	if (paint_and_count(&map->grid[y + 1][x], map) == 1)
		paintnear(y + 1, x, map);
	if (paint_and_count(&map->grid[y - 1][x], map) == 1)
		paintnear(y - 1, x, map);
	if (paint_and_count(&map->grid[y][x + 1], map) == 1)
		paintnear(y, x + 1, map);
	if (paint_and_count(&map->grid[y][x - 1], map) == 1)
		paintnear(y, x - 1, map);
}

int	flood_fill(t_data *data)
{
	t_map	*flood;

	if (!data || !data->map)
		return (0);
	flood = NULL;
	flood = start_map(flood);
	flood->grid = dupe_map(data->map);
	if (!flood || !flood->grid)
		return (0);
	paintnear(data->player->y, data->player->x, flood);
	if (flood->n_exit < 1)
	{
		free_map(&flood);
		error_and_exit(data, "ERROR! Unreachable Exit\n");
	}
	else if (flood->n_collect < data->map->n_collect)
	{
		free_map(&flood);
		error_and_exit(data, "ERROR! Unreachable Collectible\n");
	}
	write_color("Map is valid (flood_filled)\n", MAGENTA);
	write_grid(flood->grid);
	free_map(&flood);
	return (1);
}
