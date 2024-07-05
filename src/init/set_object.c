/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:17:16 by tsomchan          #+#    #+#             */
/*   Updated: 2024/07/06 01:27:44 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	add_collectible(t_collect **collect, int x, int y)
{
	t_collect	*new;
	t_collect	*tmp;

	new = malloc(sizeof(t_collect));
	new->next = NULL;
	new->x = x;
	new->y = y;
	if (!*collect)
	{
		*collect = new;
		return (1);
	}
	tmp = *collect;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (1);
}

int	add_patrol(t_patrol **patrol, int x, int y)
{
	t_patrol	*new;
	t_patrol	*tmp;

	new = malloc(sizeof(t_patrol));
	new->next = NULL;
	new->x = x;
	new->y = y;
	new->move_pts = 0;
	new->move_spd = 0.5;
	new->facing = 0;
	new->steps_needed = 0;
	new->is_on_collect = 0;
	if (!*patrol)
	{
		*patrol = new;
		return (1);
	}
	tmp = *patrol;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (1);
}
