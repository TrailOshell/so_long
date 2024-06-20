/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:13:58 by tsomchan          #+#    #+#             */
/*   Updated: 2024/06/19 19:25:24by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_top_bottom(char **grid, int x, int y)
{
	int		i;

	i = 0;
	while (i <= x)
	{
		if (grid[0][i] != '1' || grid[y][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

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
				map->n_collect += add_collectible(data->collect, col, row);
			col++;
		}
		row++;
	}
	if (map->n_collect == 0 || map->n_player != 1 || map->n_exit != 1)
		return (0);
	return (1);
}

int	check_layout(t_data *data, char **grid)
{
	int		x;
	int		y;

	x = data->map->n_col - 1;
	y = data->map->n_row - 1;
	if (check_top_bottom(grid, x, y) == 0)
		error_and_exit(data, "ERROR! top bottom error\n");
	if (count_valid_char(data, grid, data->map) == 0)
		error_and_exit(data, "ERROR! invalid char error\n");
	return (1);
}

// why not use data->grid instead of char ***grid ?
void	set_map(t_data *data, t_node *node)
{
	//t_node	*tmp;
	// int		x;
	int		y;

	data->map->grid = new_map(data->map);
	y = 0;
	// while (y < data->map->n_row)
	while (node != NULL)
	{
		// x = 0;
		// while (node->line[x])
		// {
		// 	(*grid)[y][x] = node->line[x];
		// 	x++;
		// }
		// (*grid)[y][x] = '\0';
		line_copy(data->map->grid[y], node->line);
		// tmp = node;
		node = node->next;
		// free(tmp->line);
		// free(tmp);
		y++;
	}
	free_node(&data->node);
	if (check_layout(data, data->map->grid) == 0)
		error_and_exit(data, "ERROR! layout error\n");
}

/*	void	set_map(char ***grid, t_node *node)
	while (line[x])
		data->map->grid[data->map->n_row][x] = line[x++];
	data->map->grid[data->map->n_row][x] = '\0';
*/

/*	count_valid_char() debug
int	count_valid_char(t_data *data, char **grid, t_map *map)
{
	int	col;
	int	row;

	row = 0;
	printf("grid[%d][%d] = %c\n", row, col, (*grid)[row][col]);
	printf("grid[%d] = %s\n", 2, grid[2]);
	printf("-- start row --\n");
	while (grid[row])
	{
		printf("-- check row[%d] --\n", row);
		printf("grid[%d] = %s\n", row, grid[row]);
		col = 0;
		printf("-- start col --\n");
		while (grid[row][col])
		{
			printf("col[%d](%c) \t", col, grid[row][col]);
			if (grid[row][col] == 'P')
				map->n_player += set_player(data->player, col, row);
			else if (grid[row][col] == 'E')
				map->n_exit += set_exit(data->exit, col, row);
			else if (grid[row][col] == 'C')
				map->n_collect += add_collectible(data->collect, col, row);
			col++;
		}
		printf("\n");
		row++;
		printf("row = %d\n", row);
		printf("-- valid --\n");
	}
	if (map->n_collect == 0 || map->n_player != 1 || map->n_exit != 1)
		return (0);
	return (1);
}
*/

/* new_map() debug
	printf("row = %d\n", data->map->n_row);
	printf("col = %d\n", data->map->n_col);
	printf("[row] = %d\n", row);
*/

/* set_map() debug
void	set_map(t_data *data, char ***grid, t_node *node)
{
	t_node	*tmp;
	int		x;
	int		y;

	*grid = new_map(data);
	y = 0;
	while (y < data->map->n_row)
	{
		x = 0;
		while (node->line[x])
		{
			printf("node->line[x] = %c\n", node->line[x]);
			(*grid)[y][x] = node->line[x];
			printf("grid[%d][%d] = %c\n", y, x, (*grid)[y][x]);
			printf("grid[y] = %s\n", (*grid)[y]);
			x++;
		}
		(*grid)[y][x] = '\0';
		printf("grid[y] = %s\n", (*grid)[y]);
		tmp = node;
		node = node->next;
		free(tmp->line);
		free(tmp);
		y++;
	}
	if (check_layout(data, *grid) == 0)
		error_and_exit(data, "ERROR! layout error\n");
}
*/