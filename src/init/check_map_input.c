/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 00:00:53 by tsomchan          #+#    #+#             */
/*   Updated: 2024/06/26 00:00:56 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_size(t_data *data)
{
	if (data->map->n_row == 1)
		error_and_exit(data, "ERROR! Only 1 row\n");
	else if (data->map->n_row == 2)
		error_and_exit(data, "ERROR! Only 2 rows\n");
	else if (data->map->n_col == 1)
		error_and_exit(data, "ERROR! Only 1 column\n");
	else if (data->map->n_col == 2)
		error_and_exit(data, "ERROR! Only 2 columns\n");
	return (1);
}

int	check_last_line(t_data *data)
{
	t_node	*tmp;
	int		i;

	tmp = data->node;
	while (tmp->next != NULL)
		tmp = tmp->next;
	i = 0;
	while (tmp->line[i])
		if (tmp->line[i++] == '\n')
			error_and_exit(data, "ERROR! Last line has newline\n");
	return (1);
}

int	check_map_by_lines(t_data *data, char **grid)
{
	char	*line;
	int		len;
	int		y;

	y = 0;
	check_last_line(data);
	while (grid[y])
	{
		line = grid[y];
		len = sl_strlen(line);
		if (line[0] == '\n' || !line[0])
			error_and_exit(data, "ERROR! Empty line found\n");
		else if (len != data->map->n_col)
			error_and_exit(data, "ERROR! Uneven length of lines\n");
		while (*line)
			if (isvalidchar(*(line++)) == 0)
				error_and_exit(data, "ERROR! Invalid char\n");
		y++;
	}
	return (1);
}

int	check_map_enclosed_walls(t_data *data, char **grid)
{
	int	x;
	int	y;
	int	i;

	x = data->map->n_col - 1;
	y = data->map->n_row - 1;
	if (grid[0][0] != '1' || grid[y][x] != '1'
		||grid[y][0] != '1' || grid[0][x] != '1')
		error_and_exit(data, "ERROR! Unenclosed walls\n");
	i = 1;
	while (i < x)
		if (i++ && (grid[0][i] != '1' || grid[y][i] != '1'))
			error_and_exit(data, "ERROR! Unenclosed walls\n");
	i = 1;
	while (i < y)
		if (i++ && (grid[i][0] != '1' || grid[i][x] != '1'))
			error_and_exit(data, "ERROR! Unenclosed walls\n");
	return (1);
}

int	check_map_chars_count(t_data *data)
{
	if (data->map->n_collect == 0)
		error_and_exit(data, "ERROR! Collectible not found\n");
	else if (data->map->n_player == 0)
		error_and_exit(data, "ERROR! Player not found\n");
	else if (data->map->n_player != 1)
		error_and_exit(data, "ERROR! Player count not equal 1\n");
	else if (data->map->n_exit == 0)
		error_and_exit(data, "ERROR! Exit not found\n");
	else if (data->map->n_exit != 1)
		error_and_exit(data, "ERROR! Exit count not equal 1\n");
	return (1);
}

/* unneeded?
		else if (check_left_right_wall(line, len) == 0)
			error_and_exit(data, "ERROR! Incorrect row layout\n");
		//else if (check_all_equal_len_lines(data, len) == 0)
*/

/*
int	check_all_equal_len_lines(t_data *data, int len)
{
	//if (len <= 0)
	//	return (0);
	//if (data->map->n_col == 0)
	//	data->map->n_col = len;
	//else if (len != data->map->n_col)
	//	return (0);
	if (len != data->map->n_col)
		return (0);
	return (1);
}
*/

/*
int	check_left_right_wall(char *line, int len)
{
	if (line[0] != '1' || line[len - 1] != '1')
		return (0);
	return (1);
}
*/

/*
int	check_valid_char(char *line)
{
	while (*line)
		if (isvalidchar(*(line++)) == 0)
			return (0);
	return (1);
}
*/
