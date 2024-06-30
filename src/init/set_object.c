/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:17:16 by tsomchan          #+#    #+#             */
/*   Updated: 2024/06/19 22:23:58 by tsomchan         ###   ########.fr       */
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

/* add_collectible() debug
int	add_collectible(t_collect *collect, int x, int y)
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
*/