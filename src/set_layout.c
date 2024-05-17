/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_layout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:13:58 by tsomchan          #+#    #+#             */
/*   Updated: 2024/05/17 16:13:59 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	isvalidchar(char c)
{
	if (c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C')
		return (1);
	else if (c == '\n')
		return (1);
	return (0);
}

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

int	set_player(t_player *player, int x, int y)
{
	player->x = x;
	player->y = y;
	return (1);
}

int	set_exit(t_exit *exit, int x, int y)
{
	exit->x = x;
	exit->y = y;
	return (1);
}

int	set_collect(t_collect *collect, int x, int y)
{
	t_collect	*new;
	t_collect	*tmp;

	printf("-- start collect --\n");
	new = malloc(sizeof(t_collect));
	new->x = x;
	new->y = y;
	printf("-- collect --\n");
	if (!collect)
	{
		collect = new;
		return (1);
	}
	tmp = collect;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	printf("-- end collect --\n");
	return (1);
}

int	count_valid_char(t_data *data, char **grid, t_map *map)
{
	int	col;
	int	row;

	row = 0;
	//printf("grid[%d][%d] = %c\n", row, col, (*grid)[row][col]);
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
			printf("-- check col[%d] (%c) --\n", col, grid[row][col]);
			if (grid[row][col] == 'P')
				map->n_player += set_player(data->player, col, row);
			else if (grid[row][col] == 'E')
				map->n_exit += set_exit(data->exit, col, row);
			else if (grid[row][col] == 'C')
				map->n_collect += set_collect(data->collect, col, row);
			col++;
		}
		row++;
		printf("row = %d\n", row);
		printf("-- valid --\n");
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
		error_and_exit();
	printf("func = %d\n", count_valid_char(data, grid, data->map));
	if (count_valid_char(data, grid, data->map) == 0)
		error_and_exit();
	return (1);
}

char	**new_grid(t_data *data)
{
	char	**grid;
	int		row;

	grid = malloc(sizeof(char **) * (data->map->n_row + 1));
	row = 0;
	while (row < data->map->n_row)
	{
		grid[row] = malloc(sizeof(char *) * (data->map->n_col + 1));
		row++;
	}
	grid[row] = NULL;
	//printf("row = %d\n", data->map->n_row);
	//printf("col = %d\n", data->map->n_col);
	//printf("[row] = %d\n", row);
	return (grid);
}

void	set_layout(t_data *data, char ***grid, t_node *node)
{
	t_node	*tmp;
	int		x;
	int		y;

	*grid = new_grid(data);
	y = 0;
	while (y < data->map->n_row)
	{
		x = 0;
		while (node->line[x])
		{
			//printf("node->line[x] = %c\n", node->line[x]);
			(*grid)[y][x] = node->line[x];
			//printf("grid[%d][%d] = %c\n", y, x, (*grid)[y][x]);
			//printf("grid[y] = %s\n", (*grid)[y]);
			x++;
		}
		(*grid)[y][x] = '\0';
		//printf("grid[y] = %s\n", (*grid)[y]);
		tmp = node;
		node = node->next;
		free(tmp->line);
		free(tmp);
		y++;
	}
	if (check_layout(data, *grid) == 0)
		error_and_exit();
}

/*	void	set_layout(char ***grid, t_node *node)
	while (line[x])
		data->map->grid[data->map->n_row][x] = line[x++];
	data->map->grid[data->map->n_row][x] = '\0';
*/