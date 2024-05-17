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

int	painting(t_map *flood, char **grid)
{
	if (!flood)
		return (0);
	if (grid == 0)
		return (0);
	return (0);
}

int	check_flood_char(t_map *map, t_map *flood)
{
	if (flood->n_player != 1 || flood->n_player != 1)
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
	painting(flood, map->grid);
	if (check_flood_char(map, flood) == 0)
	{
		free(flood);
		return (0);
	}
	free(flood);
	return (1);
}
