/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:00:41 by tsomchan          #+#    #+#             */
/*   Updated: 2024/06/21 16:00:43 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*load_a_sprite(t_data *data, char *filename)
{
	void	*ptr;
	char	*pth;
	int		size;

	size = SIZE;
	if (SIZE == 16)
		pth = sl_strjoin(PTH_16, filename);
	else if (SIZE == 32)
		pth = sl_strjoin(PTH_32, filename);
	else if (SIZE == 64)
		pth = sl_strjoin(PTH_64, filename);
	else if (SIZE == 128)
		pth = sl_strjoin(PTH_128, filename);
	else
		pth = sl_strjoin(PTH_64, filename);
	ptr = mlx_xpm_file_to_image(data->mlx, pth, &(size), &(size));
	free(pth);
	return (ptr);
}

void	load_pl_sprites(t_data *data)
{
	data->sprite.pl_s.up = load_a_sprite(data, PL_S_UP);
	data->sprite.pl_s.down = load_a_sprite(data, PL_S_DOWN);
	data->sprite.pl_s.left = load_a_sprite(data, PL_S_LEFT);
	data->sprite.pl_s.right = load_a_sprite(data, PL_S_RIGHT);
	data->sprite.pl_b.up = load_a_sprite(data, PL_B_UP);
	data->sprite.pl_b.down = load_a_sprite(data, PL_B_DOWN);
	data->sprite.pl_b.left = load_a_sprite(data, PL_B_LEFT);
	data->sprite.pl_b.right = load_a_sprite(data, PL_B_RIGHT);
	data->sprite.pl_m.up = load_a_sprite(data, PL_M_UP);
	data->sprite.pl_m.down = load_a_sprite(data, PL_M_DOWN);
	data->sprite.pl_m.left = load_a_sprite(data, PL_M_LEFT);
	data->sprite.pl_m.right = load_a_sprite(data, PL_M_RIGHT);
	data->sprite.pl_c.up = load_a_sprite(data, PL_C_UP);
	data->sprite.pl_c.down = load_a_sprite(data, PL_C_DOWN);
	data->sprite.pl_c.left = load_a_sprite(data, PL_C_LEFT);
	data->sprite.pl_c.right = load_a_sprite(data, PL_C_RIGHT);
	data->sprite.pl_h.up = load_a_sprite(data, PL_H_UP);
	data->sprite.pl_h.down = load_a_sprite(data, PL_H_DOWN);
	data->sprite.pl_h.left = load_a_sprite(data, PL_H_LEFT);
	data->sprite.pl_h.right = load_a_sprite(data, PL_H_RIGHT);
	//data->sprite.t.up = load_a_sprite(data, PL_T_UP);
	//data->sprite.t.down = load_a_sprite(data, PL_T_DOWN);
	//data->sprite.t.left = load_a_sprite(data, PL_T_LEFT);
	//data->sprite.t.right = load_a_sprite(data, PL_T_RIGHT);
	//data->sprite.t_r.up = load_a_sprite(data, PL_T_R_UP);
	//data->sprite.t_r.down = load_a_sprite(data, PL_T_R_DOWN);
	//data->sprite.t_r.left = load_a_sprite(data, PL_T_R_LEFT);
	//data->sprite.t_r.right = load_a_sprite(data, PL_T_R_RIGHT);
}

void	load_pt_sprites(t_data *data)
{
	data->sprite.pt_s.up = load_a_sprite(data, PT_S_UP);
	data->sprite.pt_s.down = load_a_sprite(data, PT_S_DOWN);
	data->sprite.pt_s.left = load_a_sprite(data, PT_S_LEFT);
	data->sprite.pt_s.right = load_a_sprite(data, PT_S_RIGHT);
	data->sprite.pt_m.up = load_a_sprite(data, PT_M_UP);
	data->sprite.pt_m.down = load_a_sprite(data, PT_M_DOWN);
	data->sprite.pt_m.left = load_a_sprite(data, PT_M_LEFT);
	data->sprite.pt_m.right = load_a_sprite(data, PT_M_RIGHT);
	data->sprite.pt_s_r.up = load_a_sprite(data, PT_S_R_UP);
	data->sprite.pt_s_r.down = load_a_sprite(data, PT_S_R_DOWN);
	data->sprite.pt_s_r.left = load_a_sprite(data, PT_S_R_LEFT);
	data->sprite.pt_s_r.right = load_a_sprite(data, PT_S_R_RIGHT);
	data->sprite.pt_m_r.up = load_a_sprite(data, PT_M_R_UP);
	data->sprite.pt_m_r.down = load_a_sprite(data, PT_M_R_DOWN);
	data->sprite.pt_m_r.left = load_a_sprite(data, PT_M_R_LEFT);
	data->sprite.pt_m_r.right = load_a_sprite(data, PT_M_R_RIGHT);
}

void	free_pt_sprites(t_data *data)
{
	mlx_destroy_image(data->mlx, data->sprite.pt_s.up);
	mlx_destroy_image(data->mlx, data->sprite.pt_s.down);
	mlx_destroy_image(data->mlx, data->sprite.pt_s.left);
	mlx_destroy_image(data->mlx, data->sprite.pt_s.right);
	mlx_destroy_image(data->mlx, data->sprite.pt_s_r.up);
	mlx_destroy_image(data->mlx, data->sprite.pt_s_r.down);
	mlx_destroy_image(data->mlx, data->sprite.pt_s_r.left);
	mlx_destroy_image(data->mlx, data->sprite.pt_s_r.right);
	mlx_destroy_image(data->mlx, data->sprite.pt_m.up);
	mlx_destroy_image(data->mlx, data->sprite.pt_m.down);
	mlx_destroy_image(data->mlx, data->sprite.pt_m.left);
	mlx_destroy_image(data->mlx, data->sprite.pt_m.right);
	mlx_destroy_image(data->mlx, data->sprite.pt_m_r.up);
	mlx_destroy_image(data->mlx, data->sprite.pt_m_r.down);
	mlx_destroy_image(data->mlx, data->sprite.pt_m_r.left);
	mlx_destroy_image(data->mlx, data->sprite.pt_m_r.right);
}

void	load_sprites(t_data *data)
{
	data->sprite.m.brick_s = load_a_sprite(data, BRICK_S);
	data->sprite.m.brick_m = load_a_sprite(data, BRICK_M);
	data->sprite.m.snow = load_a_sprite(data, SNOW);
	data->sprite.o.collectible = load_a_sprite(data, MATCH);
	data->sprite.o.exit_off = load_a_sprite(data, EXIT_OFF);
	data->sprite.o.exit_on = load_a_sprite(data, EXIT_ON);
	data->sprite.pl.up = load_a_sprite(data, PL_UP);
	data->sprite.pl.down = load_a_sprite(data, PL_DOWN);
	data->sprite.pl.left = load_a_sprite(data, PL_LEFT);
	data->sprite.pl.right = load_a_sprite(data, PL_RIGHT);
	load_pl_sprites(data);
	load_pt_sprites(data);
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

/*
	mlx_destroy_image(data->mlx, data->map.brick);
	mlx_destroy_image(data->mlx, data->map.snow);
	check_free_sprite(data->mlx, data->map->sprites.brick);
	check_free_sprite(data->mlx, data->map->sprites.snow);
*/
/*
void	check_free_sprite(void *mlx, void *img)
{
	if (!img)
		return ;
	if (img)
	mlx_destroy_image(mlx, img);
}
*/
/*
	data->map.brick_s = mlx_xpm_file_to_image(data->mlx, \
			BRICK_S, &size, &size);
	data->map.brick_m = mlx_xpm_file_to_image(data->mlx, \
			BRICK_M, &size, &size);
	data->map.snow = mlx_xpm_file_to_image(data->mlx, \
			SNOW, &size, &size);
	data->obj.collectible = mlx_xpm_file_to_image(data->mlx, \
			MATCH, &size, &size);
	data->obj.exit_off = mlx_xpm_file_to_image(data->mlx, \
			EXIT_OFF, &size, &size);
	data->obj.exit_on = mlx_xpm_file_to_image(data->mlx, \
			EXIT_ON, &size, &size);
	data->pl.up = mlx_xpm_file_to_image(data->mlx, \
			PL_UP, &size, &size);
	data->pl.down = mlx_xpm_file_to_image(data->mlx, \
			PL_DOWN, &size, &size);
	data->pl.left = mlx_xpm_file_to_image(data->mlx, \
			PL_LEFT, &size, &size);
	data->pl.right = mlx_xpm_file_to_image(data->mlx, \
			PL_RIGHT, &size, &size);
*/