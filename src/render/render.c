/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:44:50 by tsomchan          #+#    #+#             */
/*   Updated: 2024/07/05 19:44:03 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_data *data, int x, int y)
{
	if (data->map->grid[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->win, \
			data->sprite.m.snow, x * SIZE, y * SIZE);
	else if (data->map->grid[y][x] == '1')
	{
		if (y + 1 < data->map->n_row && data->map->grid[y + 1][x] == '1')
			mlx_put_image_to_window(data->mlx, data->win, \
				data->sprite.m.brick_m, x * SIZE, y * SIZE);
		else
			mlx_put_image_to_window(data->mlx, data->win, \
				data->sprite.m.brick_s, x * SIZE, y * SIZE);
	}
	else if (data->map->grid[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, \
			data->sprite.o.collectible, x * SIZE, y * SIZE);
	else if (data->map->grid[y][x] == 'E')
	{
		if (data->map->n_collect > 0)
			mlx_put_image_to_window(data->mlx, data->win, \
				data->sprite.o.exit_off, x * SIZE, y * SIZE);
		else if (data->map->n_collect == 0)
			mlx_put_image_to_window(data->mlx, data->win, \
				data->sprite.o.exit_on, x * SIZE, y * SIZE);
	}
}

void	render_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map->grid[y])
	{
		x = 0;
		while (data->map->grid[y][x])
		{
			render_tile(data, x, y);
			x++;
		}
		y++;
	}
}

void	render_pl_direction(t_data *data, t_pl_sprite player, int x, int y)
{
	if (y == -1)
		mlx_put_image_to_window(data->mlx, data->win, player.up, \
			data->player->x * SIZE, (data->player->y * SIZE) - SIZE);
	else if (y == 1)
		mlx_put_image_to_window(data->mlx, data->win, player.down, \
			data->player->x * SIZE, (data->player->y * SIZE) - SIZE);
	else if (x == -1)
		mlx_put_image_to_window(data->mlx, data->win, player.left, \
			data->player->x * SIZE, (data->player->y * SIZE) - SIZE);
	else if (x == 1)
		mlx_put_image_to_window(data->mlx, data->win, player.right, \
			data->player->x * SIZE, (data->player->y * SIZE) - SIZE);
	else
		mlx_put_image_to_window(data->mlx, data->win, player.down, \
			data->player->x * SIZE, (data->player->y * SIZE) - SIZE);
}

int	pt_move_pts(t_data *data, int pt_x, int pt_y)
{
	t_patrol	*curr_patrol;

	curr_patrol = data->patrol;
	while (curr_patrol)
	{
		if (curr_patrol->x == pt_x && curr_patrol->y == pt_y)
			return (curr_patrol->move_pts);
		curr_patrol = curr_patrol->next;
	}
	return (0);
}

int	pt_on_collect(t_data *data, int pt_x, int pt_y)
{
	t_patrol	*curr_patrol;

	curr_patrol = data->patrol;
	while (curr_patrol)
	{
		if (curr_patrol->x == pt_x && curr_patrol->y == pt_y)
			return (curr_patrol->is_on_collect);
		curr_patrol = curr_patrol->next;
	}
	return (0);
}

void	render_pl_front_pt(t_data *data, int x, int y)
{
	int	pt_x;
	int	pt_y;

	pt_x = data->player->x;
	pt_y = data->player->y - 1;
	if (pt_on_collect(data, pt_y, pt_x) == 1)
	{
		if (pt_move_pts(data, pt_y, pt_x) == 0)
			render_pl_direction(data, data->sprite.pl_t_m, x, y);
		else
			render_pl_direction(data, data->sprite.pl_t_m_r, x, y);
	}
	else
	{
		if (pt_move_pts(data, pt_y, pt_x) == 0)
			render_pl_direction(data, data->sprite.pl_t, x, y);
		else
			render_pl_direction(data, data->sprite.pl_t_r, x, y);
	}
}

void	render_player(t_data *data, int x, int y)
{
	char	top_tile;

	top_tile = data->map->grid[data->player->y - 1][data->player->x];
	if (top_tile == '0')
		render_pl_direction(data, data->sprite.pl_s, x, y);
	else if (top_tile == '1')
		render_pl_direction(data, data->sprite.pl_b, x, y);
	else if (top_tile == 'C')
		render_pl_direction(data, data->sprite.pl_m, x, y);
	else if (top_tile == 'E')
	{
		if (data->map->n_collect > 0)
			render_pl_direction(data, data->sprite.pl_c, x, y);
		else if (data->map->n_collect == 0)
			render_pl_direction(data, data->sprite.pl_h, x, y);
	}
	else if (top_tile == 'T')
		render_pl_front_pt(data, x, y);
	else
		render_pl_direction(data, data->sprite.pl_s, x, y);
}

void	render_patrol(t_data *data)
{
	t_patrol	*pt;

	pt = data->patrol;
	while (pt)
	{
		if (pt->is_on_collect == 0)
		{
			if (pt->move_pts == 0)
				mlx_put_image_to_window(data->mlx, data->win, \
					data->sprite.pt_s.down, pt->x * SIZE, pt->y * SIZE);
			else
				mlx_put_image_to_window(data->mlx, data->win, \
					data->sprite.pt_s_r.down, pt->x * SIZE, pt->y * SIZE);
		}
		else if (pt->is_on_collect == 1)
		{
			if (pt->move_pts == 0)
				mlx_put_image_to_window(data->mlx, data->win, \
					data->sprite.pt_m.down, pt->x * SIZE, pt->y * SIZE);
			else
				mlx_put_image_to_window(data->mlx, data->win, \
					data->sprite.pt_m_r.down, pt->x * SIZE, pt->y * SIZE);
		}
		pt = pt->next;
	}
}

/*
void	render_pt_direction(t_data *data, t_pt_sprite patrol, int x, int y)
{
	if (y == -1)
		mlx_put_image_to_window(data->mlx, data->win, patrol.up, \
			x * SIZE, y * SIZE);
	else if (y == 1)
		mlx_put_image_to_window(data->mlx, data->win, patrol.down, \
			x * SIZE, y * SIZE);
	else if (x == -1)
		mlx_put_image_to_window(data->mlx, data->win, patrol.left, \
			x * SIZE, y * SIZE);
	else if (x == 1)
		mlx_put_image_to_window(data->mlx, data->win, patrol.right, \
			x * SIZE, y * SIZE);
	else
		mlx_put_image_to_window(data->mlx, data->win, patrol.down, \
			x * SIZE, y * SIZE);
}
*/

/*
void	render_collect(t_data *data, t_collect *collect)
{
	while (collect)
	{
		mlx_put_image_to_window(data->mlx, data->win, \
			data->obj.collectible, collect->x * SIZE, collect->y * SIZE);
		collect = collect->next;
	}
}
*/

/* 
void	render_objects(t_data *data)
{
	render_collect(data, data->collect);
	if (data->map->n_collect > 0)
		mlx_put_image_to_window(data->mlx, data->win, data->obj.exit_off, \
			data->exit->x * SIZE, data->exit->y * SIZE);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->obj.exit_on, \
			data->exit->x * SIZE, data->exit->y * SIZE);
}
*/

/*
void	render_tile(t_data *data, int x, int y)
{
	else if (iswalkable(data->map->grid[y][x]) == 1 \
		|| data->map->grid[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, \
			data->map.snow, x * SIZE, y * SIZE);
	t_map_sprite	map;

	map = data->map->sprites;
}
*/