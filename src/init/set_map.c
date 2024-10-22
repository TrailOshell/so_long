/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:42:30 by tsomchan          #+#    #+#             */
/*   Updated: 2024/07/06 01:27:31 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_valid_char(t_data *data, char **grid, t_map *map)
{
	int	col;
	int	row;

	row = 0;
	while (grid[row])
	{
		col = 0;
		while (grid[row][col])
		{
			if (grid[row][col] == 'P')
				map->n_player += set_player(data->player, col, row);
			else if (grid[row][col] == 'E')
				map->n_exit += set_exit(data->exit, col, row);
			else if (grid[row][col] == 'C')
				map->n_collect += add_collectible(&data->collect, col, row);
			else if (grid[row][col] == 'T')
				map->n_patrol += add_patrol(&data->patrol, col, row);
			col++;
		}
		row++;
	}
	return (1);
}

void	set_map(t_data *data, t_node *node)
{
	int		y;

	data->map->grid = new_map(data->map);
	y = 0;
	while (node != NULL)
	{
		line_copy(data->map->grid[y], node->line);
		node = node->next;
		y++;
	}
	check_map_by_lines(data, data->map->grid);
	count_valid_char(data, data->map->grid, data->map);
	check_map_size(data);
	check_map_enclosed_walls(data, data->map->grid);
	check_map_chars_count(data);
	free_node(&data->node);
}

/*
	printf("x = %d y = %d\n", x, y);
		printf("i = %d\n", i);
		printf("%s\n", grid[i]);
		printf("%c %c\n", grid[i][0], grid[i][x]);
		printf("result = %d\n", grid[i][0] != '1' || grid[i][x] != '1');
			printf("%c %c\n", grid[i][0], grid[i][x]);
			printf("result = %d\n", grid[i][0] != '1' || grid[i][x] != '1');
		printf("i = %d\n", i);
*/