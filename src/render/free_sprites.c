/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:33:27 by tsomchan          #+#    #+#             */
/*   Updated: 2024/07/05 19:55:30 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_pl_t_sprites(t_data *data)
{
	mlx_destroy_image(data->mlx, data->sprite.pl_t.up);
	mlx_destroy_image(data->mlx, data->sprite.pl_t.down);
	mlx_destroy_image(data->mlx, data->sprite.pl_t.left);
	mlx_destroy_image(data->mlx, data->sprite.pl_t.right);
	mlx_destroy_image(data->mlx, data->sprite.pl_t_r.up);
	mlx_destroy_image(data->mlx, data->sprite.pl_t_r.down);
	mlx_destroy_image(data->mlx, data->sprite.pl_t_r.left);
	mlx_destroy_image(data->mlx, data->sprite.pl_t_r.right);
	mlx_destroy_image(data->mlx, data->sprite.pl_t_m.up);
	mlx_destroy_image(data->mlx, data->sprite.pl_t_m.down);
	mlx_destroy_image(data->mlx, data->sprite.pl_t_m.left);
	mlx_destroy_image(data->mlx, data->sprite.pl_t_m.right);
	mlx_destroy_image(data->mlx, data->sprite.pl_t_m_r.up);
	mlx_destroy_image(data->mlx, data->sprite.pl_t_m_r.down);
	mlx_destroy_image(data->mlx, data->sprite.pl_t_m_r.left);
	mlx_destroy_image(data->mlx, data->sprite.pl_t_m_r.right);
}

void	free_pl_sprites(t_data *data)
{
	mlx_destroy_image(data->mlx, data->sprite.pl_s.up);
	mlx_destroy_image(data->mlx, data->sprite.pl_s.down);
	mlx_destroy_image(data->mlx, data->sprite.pl_s.left);
	mlx_destroy_image(data->mlx, data->sprite.pl_s.right);
	mlx_destroy_image(data->mlx, data->sprite.pl_b.up);
	mlx_destroy_image(data->mlx, data->sprite.pl_b.down);
	mlx_destroy_image(data->mlx, data->sprite.pl_b.left);
	mlx_destroy_image(data->mlx, data->sprite.pl_b.right);
	mlx_destroy_image(data->mlx, data->sprite.pl_m.up);
	mlx_destroy_image(data->mlx, data->sprite.pl_m.down);
	mlx_destroy_image(data->mlx, data->sprite.pl_m.left);
	mlx_destroy_image(data->mlx, data->sprite.pl_m.right);
	mlx_destroy_image(data->mlx, data->sprite.pl_c.up);
	mlx_destroy_image(data->mlx, data->sprite.pl_c.down);
	mlx_destroy_image(data->mlx, data->sprite.pl_c.left);
	mlx_destroy_image(data->mlx, data->sprite.pl_c.right);
	mlx_destroy_image(data->mlx, data->sprite.pl_h.up);
	mlx_destroy_image(data->mlx, data->sprite.pl_h.down);
	mlx_destroy_image(data->mlx, data->sprite.pl_h.left);
	mlx_destroy_image(data->mlx, data->sprite.pl_h.right);
	free_pl_t_sprites(data);
}

void	free_pt_sprites(t_data *data)
{
	mlx_destroy_image(data->mlx, data->sprite.pt_s.down);
	mlx_destroy_image(data->mlx, data->sprite.pt_s_r.down);
	mlx_destroy_image(data->mlx, data->sprite.pt_m.down);
	mlx_destroy_image(data->mlx, data->sprite.pt_m_r.down);
}

void	free_sprites(t_data *data)
{
	if (data->sprite.m.snow)
		mlx_destroy_image(data->mlx, data->sprite.m.snow);
	if (data->sprite.m.brick_s)
		mlx_destroy_image(data->mlx, data->sprite.m.brick_s);
	if (data->sprite.m.brick_m)
		mlx_destroy_image(data->mlx, data->sprite.m.brick_m);
	if (data->sprite.o.collectible)
		mlx_destroy_image(data->mlx, data->sprite.o.collectible);
	if (data->sprite.o.exit_off)
		mlx_destroy_image(data->mlx, data->sprite.o.exit_off);
	if (data->sprite.o.exit_on)
		mlx_destroy_image(data->mlx, data->sprite.o.exit_on);
	if (data->sprite.pl.up)
		mlx_destroy_image(data->mlx, data->sprite.pl.up);
	if (data->sprite.pl.down)
		mlx_destroy_image(data->mlx, data->sprite.pl.down);
	if (data->sprite.pl.left)
		mlx_destroy_image(data->mlx, data->sprite.pl.left);
	if (data->sprite.pl.right)
		mlx_destroy_image(data->mlx, data->sprite.pl.right);
	free_pl_sprites(data);
	free_pt_sprites(data);
}
