/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 22:19:20 by tsomchan          #+#    #+#             */
/*   Updated: 2024/06/19 22:23:58 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**new_grid(t_map *map)
{
	char	**grid;
	int		row;

	grid = malloc(sizeof(char **) * (map->n_row + 1));
	row = 0;
	while (row < map->n_row)
	{
		grid[row] = malloc(sizeof(char *) * (map->n_col + 1));
		row++;
	}
	grid[row] = NULL;
	return (grid);
}

char	**dupe_grid(char **map)
{
	char	**dupe;
	// int		x;
	int		y;

	dupe = new_grid(data->map);
	y = 0;
	while (map[y])
	{
		// x = 0;
		// while (map[y][x])
		// {
		// 	dupe[y][x] = map[y][x];
		// 	x++;
		// }
		// dupe[y][x] = '\0';
		line_copy(dupe[y], map[y]);
		y++;
	}
	return (dupe);
}

