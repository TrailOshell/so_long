/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:30:18 by tsomchan          #+#    #+#             */
/*   Updated: 2024/06/19 22:19:42 by tsomchan         ###   ########.fr       */
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

/* int	paintnear(int x, int y, char **grid)
	int	ispainted;

	ispainted = 0;
	if (iswalkable(x, y, grid))
	{
		grid[x][y] = 'P';
		ispainted = 1;
	}
	if (ispainted == 1)
	{
		paintnear(x + 1, y, grid);
		paintnear(x - 1, y, grid);
		paintnear(x, y + 1, grid);
		paintnear(x, y - 1, grid);
	}
*/
/*
	if (iswalkable(right) == 1)
		right = 'P'; paintnear(x + 1, y, map);
	if (iswalkable(left) == 1)
		left = 'P'; paintnear(x - 1, y, map);
	if (iswalkable(up) == 1)
		up = 'P'; paintnear(x, y + 1, map);
	if (iswalkable(down) == 1)
		down = 'P'; paintnear(x, y - 1, map);
*/

/* check_flood_char() debug
int	check_flood_char(t_map *map, t_map *flood)
{
	if (flood->n_player != 1)
		error_and_exit(data, "ERROR! multiple players found\n");
	if (flood->n_exit == 0)
		return (0);
	{
		free(flood);
		free(map);
		error_and_exit(data, "ERROR! Unreachable exit\n");
	}
	else if (flood->n_collect != map->n_collect)
		return (0);
	{
		free(flood);
		error_and_exit(data, "ERROR! Unreachable collectible found\n");
	}
	return (1);
}
*/

/* flood_fill() debug
int	flood_fill(t_data *data, t_map *map)
{
	t_map	*flood;

	write_grid(map->grid);
	if (!data)
		return (0);
	flood = NULL;
	flood = start_map(flood);
	flood->grid = new_map(data);
	painting(data, flood, map->grid);
	write_grid(flood->grid);
	printf("flood->n_collect = %d\n", flood->n_collect);
	printf("map->n_collect = %d\n", map->n_collect);
	printf("flood->n_exit = %d\n", flood->n_exit);
	printf("map->n_exit = %d\n", map->n_exit);
	if (check_flood_char(map, flood) == 0)
	{
		free(flood);
		return (0);
	}
	free(flood);
	return (1);
}
*/