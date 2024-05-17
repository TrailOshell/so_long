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

int	read_map(char **argv, t_data *data)
{
	int		fd;

	printf("open(argv[1], O_RDONLY) = \"%s\"\n", argv[1]);
	fd = open(argv[1], O_RDONLY);
	//printf("fd = %d\n", fd);
	if (fd < 0)
		error_and_exit();
	if (sl_strrncmp(argv[1], ".ber", 4))
		error_and_exit();
	//printf("next\n");
	//printf("data->node->line = %s\n", data->node->line);
	//printf("data->node->line = %s\n", data->node->next->line);
	//printf("data->node->line = %s\n", data->node->next->next->line);
	get_next_row(data, fd);
	set_layout(data, &data->map->grid, data->node);
	flood_fill(data, data->map);
	return (1);
}
