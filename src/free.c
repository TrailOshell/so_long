/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:38:27 by tsomchan          #+#    #+#             */
/*   Updated: 2024/06/19 22:10:46 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	if (data->map->grid)
	{
		i = 0;
		while (data->map->grid[i])
			free(data->map->grid[i++]);
		free(data->map->grid);
	}
	free(data->map);
}

void	free_collect(t_collect *collect)
{
	t_collect	*tmp;

	while (collect->next)
	{
		tmp = collect;
		collect = collect->next;
		free(tmp);
	}
	free(collect);
}

void	free_node(t_node *node)
{
	t_node	*tmp;

	while (node->next)
	{
		tmp = node;
		node = node->next;
		free(tmp);
	}
	free(node);
}

void	free_stuff(t_data *data)
{
	if (data)
	{
		if (data->mlx_ptr)
			free(data->mlx_ptr);
		if (data->player)
			free(data->player);
		if (data->exit)
			free(data->exit);
		if (data->collect)
			free_collect(data->collect);
		if (data->map)
			free_map(map);
		if (data->node)
			free_node(node);
		free(data);
	}
}
