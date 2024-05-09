/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 19:51:24 by tsomchan          #+#    #+#             */
/*   Updated: 2024/05/09 19:51:25 by tsomchan         ###   ########.fr       */
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

int	check_map_col(t_data *data, int len)
{
	if (len <= 0)
		return (0);
	if (data->map->n_col == 0)
		data->map->n_col = len;
	else if (len != data->map->n_col)
		return (0);
	return (1);
}

/*	int	check_map_col(t_data *data, char *line, int len)
	if (data->map->n_row == 0)
		while (line)
			if ((*line)++ != 1)
				return (0);
*/

int	check_map_row(char *line, int len)
{
	if (line[0] != 1 || line [len] != 1)
		return (0);
	while (line)
		if (isvalidchar((*line)++) == 0)
			return (0);
	return (1);
}

void	add_line(t_node *node, char *line)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	new->line = sl_strdup(line);
	if (!node)
	{
		node = new;
		return ;
	}
	while (node->next)
		node = node->next;
	node->next = new;
}

int	check_top_bottom(char **grid, int x, int y)
{
	int		i;

	i = 0;
	while (i <= x)
	{
		if (grid[0][i] != 1 || grid [y][i] != 1)
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

	new = malloc(sizeof(t_collect));
	new->x = x;
	new->y = y;
	if (!collect)
	{
		collect = new;
		return (1);
	}
	while (collect->next)
		collect = collect->next;
	collect->next = new;
	return (1);
}

int	count_valid_char(t_data *data, char **grid, t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (grid[j])
	{
		i = 0;
		while (grid[j][i])
		{
			if (grid[j][i] == 'P')
				map->n_player += set_player(data->player, i, j);
			else if (grid[j][i] == 'E')
				map->n_exit += set_exit(data->exit, i, j);
			else if (grid[j][i] == 'C')
				map->n_collect += set_collect(data->collect, i, j);
			i++;
		}
		j++;
	}
	if (map->n_collect == 0 || map->n_player != 1 || map->n_exit != 1)
		return (0);
	return (1);
}

int	check_clear_path(data, grid)
{

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
	if (count_valid_char(data, grid, data->map) == 0)
		error_and_exit();
	if (check_clear_path(data, grid) == 0);
		error_and_exit();
	return (1);
}

void	set_layout(t_data *data, char ***grid, t_node *node)
{
	t_node	*tmp;
	int		x;
	int		y;

	y = 0;
	while (node)
	{
		x = 0;
		while (node->line[x])
		{
			*(grid[y][x]) = node->line[x];
			x++;
		}
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

int	read_map(int argc, char **argv, t_data *data)
{
	char	*line;
	int		len;
	int		fd;

	if (argc != 2)
		error_and_exit();
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_and_exit();
	if (sl_strrncmp(argv[1], ".ber", 4))
		error_and_exit();
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len = sl_strlen(line);
		if (check_map_col(data, len) == 0 || check_map_row(line, len) == 0)
			error_and_exit();
		add_line(&data->node, line);
		free(line);
		data->map->n_row++;
	}
	set_layout(data, &data->map->grid, &data->node);
}
