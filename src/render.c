/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:44:50 by tsomchan          #+#    #+#             */
/*   Updated: 2024/06/21 15:44:51 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_data *data, int x, int y)
{
	if (data->map->grid[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->win, \
			data->m_sprites.snow, x * SIZE, y * SIZE);
	else if (data->map->grid[y][x] == '1')
	{
		if (y + 1 < data->map->n_row && data->map->grid[y + 1][x] == '1')
			mlx_put_image_to_window(data->mlx, data->win, \
				data->m_sprites.brick_m, x * SIZE, y * SIZE);
		else
			mlx_put_image_to_window(data->mlx, data->win, \
				data->m_sprites.brick_s, x * SIZE, y * SIZE);
	}
	else if (data->map->grid[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, \
			data->o_sprites.collectible, x * SIZE, y * SIZE);
	else if (data->map->grid[y][x] == 'E')
	{
		if (data->map->n_collect > 0)
			mlx_put_image_to_window(data->mlx, data->win, \
				data->o_sprites.exit_off, x * SIZE, y * SIZE);
		else if (data->map->n_collect == 0)
			mlx_put_image_to_window(data->mlx, data->win, \
				data->o_sprites.exit_on, x * SIZE, y * SIZE);
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

void	render_player(t_data *data, int x, int y)
{
	char	top_tile;

	top_tile = data->map->grid[data->player->y - 1][data->player->x];
	if (top_tile == '0')
		render_pl_direction(data, data->p_sprites_s, x, y);
	else if (top_tile == '1')
		render_pl_direction(data, data->p_sprites_b, x, y);
	else if (top_tile == 'C')
		render_pl_direction(data, data->p_sprites_m, x, y);
	else if (top_tile == 'E')
	{
		if (data->map->n_collect > 0)
			render_pl_direction(data, data->p_sprites_c, x, y);
		else if (data->map->n_collect == 0)
			render_pl_direction(data, data->p_sprites_h, x, y);
	}
	else
		render_pl_direction(data, data->p_sprites_s, x, y);
}

/*
void	render_collect(t_data *data, t_collect *collect)
{
	while (collect)
	{
		mlx_put_image_to_window(data->mlx, data->win, \
			data->o_sprites.collectible, collect->x * SIZE, collect->y * SIZE);
		collect = collect->next;
	}
}
*/

/* 
void	render_objects(t_data *data)
{
	render_collect(data, data->collect);
	if (data->map->n_collect > 0)
		mlx_put_image_to_window(data->mlx, data->win, data->o_sprites.exit_off, \
			data->exit->x * SIZE, data->exit->y * SIZE);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->o_sprites.exit_on, \
			data->exit->x * SIZE, data->exit->y * SIZE);
}
*/

/*
void	render_tile(t_data *data, int x, int y)
{
	else if (iswalkable(data->map->grid[y][x]) == 1 \
		|| data->map->grid[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->win, \
			data->m_sprites.snow, x * SIZE, y * SIZE);
	t_map_sprite	m_sprites;

	m_sprites = data->map->sprites;
}
*/