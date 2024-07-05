/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:00:41 by tsomchan          #+#    #+#             */
/*   Updated: 2024/07/06 01:30:08 by tsomchan         ###   ########.fr       */
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

void	load_pl_t_sprites(t_data *data)
{
	data->sprite.pl_t.up = load_a_sprite(data, PL_T_UP);
	data->sprite.pl_t.down = load_a_sprite(data, PL_T_DOWN);
	data->sprite.pl_t.left = load_a_sprite(data, PL_T_LEFT);
	data->sprite.pl_t.right = load_a_sprite(data, PL_T_RIGHT);
	data->sprite.pl_t_r.up = load_a_sprite(data, PL_T_R_UP);
	data->sprite.pl_t_r.down = load_a_sprite(data, PL_T_R_DOWN);
	data->sprite.pl_t_r.left = load_a_sprite(data, PL_T_R_LEFT);
	data->sprite.pl_t_r.right = load_a_sprite(data, PL_T_R_RIGHT);
	data->sprite.pl_t_m.up = load_a_sprite(data, PL_T_M_UP);
	data->sprite.pl_t_m.down = load_a_sprite(data, PL_T_M_DOWN);
	data->sprite.pl_t_m.left = load_a_sprite(data, PL_T_M_LEFT);
	data->sprite.pl_t_m.right = load_a_sprite(data, PL_T_M_RIGHT);
	data->sprite.pl_t_m_r.up = load_a_sprite(data, PL_T_M_R_UP);
	data->sprite.pl_t_m_r.down = load_a_sprite(data, PL_T_M_R_DOWN);
	data->sprite.pl_t_m_r.left = load_a_sprite(data, PL_T_M_R_LEFT);
	data->sprite.pl_t_m_r.right = load_a_sprite(data, PL_T_M_R_RIGHT);
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
	load_pl_t_sprites(data);
}

void	load_pt_sprites(t_data *data)
{
	data->sprite.pt_s.down = load_a_sprite(data, PT_S_DOWN);
	data->sprite.pt_m.down = load_a_sprite(data, PT_M_DOWN);
	data->sprite.pt_s_r.down = load_a_sprite(data, PT_S_R_DOWN);
	data->sprite.pt_m_r.down = load_a_sprite(data, PT_M_R_DOWN);
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
