/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_row.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:43:01 by tsomchan          #+#    #+#             */
/*   Updated: 2024/06/21 16:43:05 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_next_row(t_data *data, int fd)
{
	char	*line;
	int		 			len;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len = sl_strlen(line);
		if (line[len - 1] == '\n')
			len--;
		if (data->map->n_col == 0)
			data->map->n_col = len;
		add_line(&data->node, line);
		free(line);
		data->map->n_row++;
	}
	if (data->node == NULL)
		error_and_exit(data, "ERROR! Empty file\n");
}
/*
	char	*line;
	int		len;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len = sl_strlen(line);
		if (line[len - 1] == '\n')
			len--;
		check_all_equal_len_lines(data, len);
		check_left_right_wall(line, len);
		add_line(&data->node, line);
		free(line);
		data->map->n_row++;
	}
	if (data->node == NULL)
		error_and_exit(data, "ERROR! Empty file\n");

*/
		//if (line[0] == '\n')
		//	error_and_exit(data, "ERROR! Empty line found\n");
		//else if (check_valid_char(line) == 0)
		//	error_and_exit(data, "ERROR! Invalid char\n");
		//else if (check_all_equal_len_lines(data, len) == 0)
		//	error_and_exit(data, "ERROR! Incorrect col and row layout\n");
		//else if (check_left_right_wall(line, len) == 0)
		//	error_and_exit(data, "ERROR! Incorrect col and row layout\n");
