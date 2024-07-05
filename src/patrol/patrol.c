/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patrol.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:47:10 by tsomchan          #+#    #+#             */
/*   Updated: 2024/07/05 20:22:05 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// set the next valid patrol that can move
t_patrol	*set_moving_patrol_move(t_patrol *patrol)
{
	t_patrol	*tmp_patrol;
	t_patrol	*moving_patrol;

	moving_patrol = NULL;
	tmp_patrol = patrol;
	while (tmp_patrol)
	{
		if (tmp_patrol->move_pts >= 1)
		{
			if (!moving_patrol)
				moving_patrol = tmp_patrol;
			else if (tmp_patrol->steps_needed < moving_patrol->steps_needed)
				moving_patrol = tmp_patrol;
		}
		tmp_patrol = tmp_patrol->next;
	}
	return (moving_patrol);
}

// every patrol check to sense the player first
void	curr_patrol_check(char **grid, t_patrol *patrol)
{
	t_patrol	*tmp_patrol;

	tmp_patrol = patrol;
	while (tmp_patrol)
	{
		if (pathfinding(grid, tmp_patrol))
			tmp_patrol->move_pts += tmp_patrol->move_spd;
		else
			tmp_patrol->move_pts = 0;
		tmp_patrol = tmp_patrol->next;
	}
}
		//printf("patrol->move_pts = %f\n", tmp_patrol->move_pts);

// patrol now move closer to the player
void	patrol_move(t_data *data, t_patrol *patrol, int x, int y)
{
	char	*target_tile;

	target_tile = &(data->map->grid[patrol->y + y][patrol->x + x]);
	if (ispatrolable(*target_tile) && *target_tile != 'T')
	{
		if (*target_tile == 'P')
		{
			write_color("GAME OVER 💀\n", RED);
			on_game_exit(data);
		}
		if (patrol->is_on_collect == 1)
			data->map->grid[patrol->y][patrol->x] = 'C';
		else
			data->map->grid[patrol->y][patrol->x] = '0';
		render_tile(data, patrol->x, patrol->y);
		if (*target_tile == 'C')
			patrol->is_on_collect = 1;
		else
			patrol->is_on_collect = 0;
		*target_tile = 'T';
		patrol->x += x;
		patrol->y += y;
	}
	patrol->move_pts -= 1;
}
// if it can't move yet I would like to code to save it's move for next turn.
// but it might be too much for now

// the main function for patroling
void	patroling(t_data *data)
{
	t_patrol	*moving_patrol;

	if (data->patrol == NULL)
		return ;
	curr_patrol_check(data->map->grid, data->patrol);
	while (1)
	{
		moving_patrol = set_moving_patrol_move(data->patrol);
		if (moving_patrol == NULL)
			break ;
		pathfinding(data->map->grid, moving_patrol);
		if (moving_patrol->facing == 'D')
			patrol_move(data, moving_patrol, 0, 1);
		else if (moving_patrol->facing == 'L')
			patrol_move(data, moving_patrol, -1, 0);
		else if (moving_patrol->facing == 'R')
			patrol_move(data, moving_patrol, 1, 0);
		else if (moving_patrol->facing == 'U')
			patrol_move(data, moving_patrol, 0, -1);
	}
	render_patrol(data);
}
		//printf("patrol->facing = %c\n", moving_patrol->facing);

/* still enough lines in patrol_move() so this function won't be needed yet
void	update_patrol(char **grid, t_patrol *patrol, int x, int y)
{
	char	*target_tile;

	target_tile = &(grid[patrol->y + y][patrol->x + x]);
	if (patrol->is_on_collect == 1)
		grid[patrol->y][patrol->x] = 'C';
	else
		grid[patrol->y][patrol->x] = '0';
	if (*target_tile == 'C')
		patrol->is_on_collect = 1;
	else
		patrol->is_on_collect = 0;
	*target_tile = 'T';
	patrol->x += x;
	patrol->y += y;
}
*/
