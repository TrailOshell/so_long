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

void	free_map(t_map **map)
{
	int	i;

	if ((*map)->grid)
	{
		i = 0;
		while ((*map)->grid[i])
			free((*map)->grid[i++]);
		free((*map)->grid);
	}
	free(*map);
	*map = NULL;
}

void	free_collect(t_collect **collect)
{
	t_collect	*tmp;

	while (*collect)
	{
		tmp = (*collect)->next;
		free(*collect);
		*collect = tmp;
	}
}

void	free_node(t_node **node)
{
	t_node	*tmp;

	while (*node)
	{
		tmp = (*node)->next;
		free((*node)->line);
		free(*node);
		*node = tmp;
	}
}

void	free_stuff(t_data *data)
{
	if (data)
	{
		if (data->mlx)
			free(data->mlx);
		if (data->player)
			free(data->player);
		if (data->exit)
			free(data->exit);
		if (data->collect)
			free_collect(&data->collect);
		if (data->map)
			free_map(&data->map);
		if (data->node != NULL)
			free_node(&data->node);
		free(data);
	}
}
