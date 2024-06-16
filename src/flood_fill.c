/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:30:18 by tsomchan          #+#    #+#             */
/*   Updated: 2024/05/16 14:30:20 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ispaintable(int x, int y, char **grid)
{
	char	c;

	c = grid[x][y];
	if (c == '0' || c == 'C' || c == 'E')
		return (1);
	return (0);
}

int	paintnear(int x, int y, char **grid)
{
	if (ispaintable(x + 1, y, grid))
	{
		grid[x + 1][y] = 'P';
		paintnear(x + 1, y, grid);
	}
	if (ispaintable(x - 1, y, grid))
	{
		grid[x - 1][y] = 'P';
		paintnear(x - 1, y, grid);
	}
	if (ispaintable(x, y + 1, grid))
	{
		grid[x][y + 1] = 'P';
		paintnear(x, y + 1, grid);
	}
	if (ispaintable(x, y - 1, grid))
	{
		grid[x][y - 1] = 'P';
		paintnear(x, y - 1, grid);
	}
	return (1);
}

/* int	paintnear(int x, int y, char **grid)
	int	ispainted;

	ispainted = 0;
	if (ispaintable(x, y, grid))
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
int	painting(t_data *data, t_map *flood, char **grid)
{
	t_node	*start;

	start = malloc(sizeof(t_node));
	start->x = data->player->x;
	start->y = data->player->y;
	if (!flood)
		return (0);
	if (!grid)
		return (0);
	dupe_grid(flood->grid, grid);
	paintnear(start->x, start->y, flood->grid);
	free(start);
	write_grid(flood->grid);
	return (1);
}

int	check_flood_char(t_map *map, t_map *flood)
{
	if (flood->n_player != 1 || flood->n_exit != 1)
		return (0);
	else if (flood->n_collect != map->n_collect)
		return (1);
	return (0);
}

int	flood_fill(t_data *data, t_map *map)
{
	t_map	*flood;

	write_grid(map->grid);
	if (!data)
		return (0);
	flood = NULL;
	flood = start_map(flood);
	flood->grid = new_grid(data);
	painting(data, flood, map->grid);
	if (check_flood_char(map, flood) == 0)
	{
		free(flood);
		return (0);
	}
	free(flood);
	return (1);
}
