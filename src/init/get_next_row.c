/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_row.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:43:01 by tsomchan          #+#    #+#             */
/*   Updated: 2024/07/06 01:27:05 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// this one keeps newline in the nodes
void	get_next_row(t_data *data, int fd)
{
	char	*line;
	int		len;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len = sl_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
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
