/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:47:21 by tsomchan          #+#    #+#             */
/*   Updated: 2024/07/04 16:47:22 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	min_valid_steps(int up, int down, int left, int right)
{
	if (down
		&& (down <= left || left == 0)
		&& (down <= right || right == 0)
		&& (down <= up || up == 0))
		return (down);
	else if (left
		&& (left <= right || right == 0)
		&& (left <= up || up == 0)
		&& (left <= down || down == 0))
		return (left);
	else if (right
		&& (right <= left || left == 0)
		&& (right <= up || up == 0)
		&& (right <= down || down == 0))
		return (right);
	else if (up
		&& (up <= left || left == 0)
		&& (up <= right || right == 0)
		&& (up <= down || down == 0))
		return (up);
	return (0);
}

char	set_next_step(int up, int down, int left, int right)
{
	if (down
		&& (down <= left || left == 0)
		&& (down <= right || right == 0)
		&& (down <= up || up == 0))
		return ('D');
	else if (left
		&& (left <= right || right == 0)
		&& (left <= up || up == 0)
		&& (left <= down || down == 0))
		return ('L');
	else if (right
		&& (right <= left || left == 0)
		&& (right <= up || up == 0)
		&& (right <= down || down == 0))
		return ('R');
	else if (up
		&& (up <= left || left == 0)
		&& (up <= right || right == 0)
		&& (up <= down || down == 0))
		return ('U');
	return (0);
}

// recursively stepping untill it find player, or run out of range 
int	find_player(char **grid, int steps, int curr_x, int curr_y)
{
	int	up;
	int	down;
	int	left;
	int	right;

	if (steps > 6 || ispatrolable(grid[curr_y][curr_x]) == 0)
		return (0);
	else if (grid[curr_y][curr_x] == 'P')
		return (steps);
	up = find_player(grid, steps + 1, curr_x, curr_y - 1);
	down = find_player(grid, steps + 1, curr_x, curr_y + 1);
	left = find_player(grid, steps + 1, curr_x - 1, curr_y);
	right = find_player(grid, steps + 1, curr_x + 1, curr_y);
	steps = min_valid_steps(up, down, left, right);
	return (steps);
}
//debug_facing_step(up, down, left, right);

// get_shortest_path
int	pathfinding(char **grid, t_patrol *patrol)
{
	int	up;
	int	down;
	int	left;
	int	right;

	patrol->facing = 0;
	up = find_player(grid, 1, patrol->x, patrol->y - 1);
	down = find_player(grid, 1, patrol->x, patrol->y + 1);
	left = find_player(grid, 1, patrol->x - 1, patrol->y);
	down = find_player(grid, 1, patrol->x, patrol->y + 1);
	right = find_player(grid, 1, patrol->x + 1, patrol->y);
	patrol->steps_needed = min_valid_steps(up, down, left, right);
	patrol->facing = set_next_step(up, down, left, right);
	debug_pathfinding(up, down, left, right);
	return (patrol->steps_needed);
}

/* broken
int	min_valid_steps(int up, int down, int left, int right)
{
	int	steps;

	steps = 1;
	if (!down && !up && !left && !right)
		return (0);
	if (down > 0)
		steps = down;
	if (left > 0 && left < steps)
		steps = left;
	if (right > 0 && right < steps)
		steps = right;
	if (up > 0 && up < steps)
		steps = up;
	return (steps);
}

char	set_next_step(int up, int down, int left, int right)
{
	int		steps;
	char	facing;

	facing = 0;
	steps = 1;
	if (!down && !up && !left && !right)
		return (0);
	if (down > 0)
	{
		steps = down;
		facing = 'D';
	}
	if (left > 0 && left < steps)
	{
		steps = left;
		facing = 'L';
	}
	if (right > 0 && right < steps)
	{
		steps = right;
		facing = 'R';
	}
	if (up > 0 && up < steps)
	{
		steps = up;
		facing = 'U';
	}
	return (facing);
}
*/