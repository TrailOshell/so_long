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

void	load_p_sprites(t_data *data)
{
	data->p_sprites_s.up = load_a_sprite(data, PL_S_UP);
	data->p_sprites_s.down = load_a_sprite(data, PL_S_DOWN);
	data->p_sprites_s.left = load_a_sprite(data, PL_S_LEFT);
	data->p_sprites_s.right = load_a_sprite(data, PL_S_RIGHT);
	data->p_sprites_b.up = load_a_sprite(data, PL_B_UP);
	data->p_sprites_b.down = load_a_sprite(data, PL_B_DOWN);
	data->p_sprites_b.left = load_a_sprite(data, PL_B_LEFT);
	data->p_sprites_b.right = load_a_sprite(data, PL_B_RIGHT);
	data->p_sprites_m.up = load_a_sprite(data, PL_M_UP);
	data->p_sprites_m.down = load_a_sprite(data, PL_M_DOWN);
	data->p_sprites_m.left = load_a_sprite(data, PL_M_LEFT);
	data->p_sprites_m.right = load_a_sprite(data, PL_M_RIGHT);
	data->p_sprites_c.up = load_a_sprite(data, PL_C_UP);
	data->p_sprites_c.down = load_a_sprite(data, PL_C_DOWN);
	data->p_sprites_c.left = load_a_sprite(data, PL_C_LEFT);
	data->p_sprites_c.right = load_a_sprite(data, PL_C_RIGHT);
	data->p_sprites_h.up = load_a_sprite(data, PL_H_UP);
	data->p_sprites_h.down = load_a_sprite(data, PL_H_DOWN);
	data->p_sprites_h.left = load_a_sprite(data, PL_H_LEFT);
	data->p_sprites_h.right = load_a_sprite(data, PL_H_RIGHT);
}

void	load_sprites(t_data *data)
{
	data->m_sprites.brick_s = load_a_sprite(data, BRICK_S);
	data->m_sprites.brick_m = load_a_sprite(data, BRICK_M);
	data->m_sprites.snow = load_a_sprite(data, SNOW);
	data->o_sprites.collectible = load_a_sprite(data, MATCH);
	data->o_sprites.exit_off = load_a_sprite(data, EXIT_OFF);
	data->o_sprites.exit_on = load_a_sprite(data, EXIT_ON);
	data->p_sprites.up = load_a_sprite(data, PL_UP);
	data->p_sprites.down = load_a_sprite(data, PL_DOWN);
	data->p_sprites.left = load_a_sprite(data, PL_LEFT);
	data->p_sprites.right = load_a_sprite(data, PL_RIGHT);
	load_p_sprites(data);
}

void	free_p_sprites(t_data *data)
{
	mlx_destroy_image(data->mlx, data->p_sprites_s.up);
	mlx_destroy_image(data->mlx, data->p_sprites_s.down);
	mlx_destroy_image(data->mlx, data->p_sprites_s.left);
	mlx_destroy_image(data->mlx, data->p_sprites_s.right);
	mlx_destroy_image(data->mlx, data->p_sprites_b.up);
	mlx_destroy_image(data->mlx, data->p_sprites_b.down);
	mlx_destroy_image(data->mlx, data->p_sprites_b.left);
	mlx_destroy_image(data->mlx, data->p_sprites_b.right);
	mlx_destroy_image(data->mlx, data->p_sprites_m.up);
	mlx_destroy_image(data->mlx, data->p_sprites_m.down);
	mlx_destroy_image(data->mlx, data->p_sprites_m.left);
	mlx_destroy_image(data->mlx, data->p_sprites_m.right);
	mlx_destroy_image(data->mlx, data->p_sprites_c.up);
	mlx_destroy_image(data->mlx, data->p_sprites_c.down);
	mlx_destroy_image(data->mlx, data->p_sprites_c.left);
	mlx_destroy_image(data->mlx, data->p_sprites_c.right);
	mlx_destroy_image(data->mlx, data->p_sprites_h.up);
	mlx_destroy_image(data->mlx, data->p_sprites_h.down);
	mlx_destroy_image(data->mlx, data->p_sprites_h.left);
	mlx_destroy_image(data->mlx, data->p_sprites_h.right);
}

void	free_sprites(t_data *data)
{
	if (data->m_sprites.snow)
		mlx_destroy_image(data->mlx, data->m_sprites.snow);
	if (data->m_sprites.brick_s)
		mlx_destroy_image(data->mlx, data->m_sprites.brick_s);
	if (data->m_sprites.brick_m)
		mlx_destroy_image(data->mlx, data->m_sprites.brick_m);
	if (data->o_sprites.collectible)
		mlx_destroy_image(data->mlx, data->o_sprites.collectible);
	if (data->o_sprites.exit_off)
		mlx_destroy_image(data->mlx, data->o_sprites.exit_off);
	if (data->o_sprites.exit_on)
		mlx_destroy_image(data->mlx, data->o_sprites.exit_on);
	if (data->p_sprites.up)
		mlx_destroy_image(data->mlx, data->p_sprites.up);
	if (data->p_sprites.down)
		mlx_destroy_image(data->mlx, data->p_sprites.down);
	if (data->p_sprites.left)
		mlx_destroy_image(data->mlx, data->p_sprites.left);
	if (data->p_sprites.right)
		mlx_destroy_image(data->mlx, data->p_sprites.right);
	free_p_sprites(data);
}

/*
	mlx_destroy_image(data->mlx, data->m_sprites.brick);
	mlx_destroy_image(data->mlx, data->m_sprites.snow);
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
	data->m_sprites.brick_s = mlx_xpm_file_to_image(data->mlx, \
			BRICK_S, &size, &size);
	data->m_sprites.brick_m = mlx_xpm_file_to_image(data->mlx, \
			BRICK_M, &size, &size);
	data->m_sprites.snow = mlx_xpm_file_to_image(data->mlx, \
			SNOW, &size, &size);
	data->o_sprites.collectible = mlx_xpm_file_to_image(data->mlx, \
			MATCH, &size, &size);
	data->o_sprites.exit_off = mlx_xpm_file_to_image(data->mlx, \
			EXIT_OFF, &size, &size);
	data->o_sprites.exit_on = mlx_xpm_file_to_image(data->mlx, \
			EXIT_ON, &size, &size);
	data->p_sprites.up = mlx_xpm_file_to_image(data->mlx, \
			PL_UP, &size, &size);
	data->p_sprites.down = mlx_xpm_file_to_image(data->mlx, \
			PL_DOWN, &size, &size);
	data->p_sprites.left = mlx_xpm_file_to_image(data->mlx, \
			PL_LEFT, &size, &size);
	data->p_sprites.right = mlx_xpm_file_to_image(data->mlx, \
			PL_RIGHT, &size, &size);
*/