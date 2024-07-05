/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_pl_front_of_pt.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:11:34 by tsomchan          #+#    #+#             */
/*   Updated: 2024/07/06 01:12:11 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	render_pl_front_of_pt(t_data *data, int x, int y)
{
	int	pt_x;
	int	pt_y;

	pt_x = data->player->x;
	pt_y = data->player->y - 1;
	if (pt_on_collect(data, pt_x, pt_y) == 1)
	{
		if (pt_move_pts(data, pt_x, pt_y) == 0)
			render_pl_direction(data, data->sprite.pl_t_m, x, y);
		else
			render_pl_direction(data, data->sprite.pl_t_m_r, x, y);
	}
	else
	{
		if (pt_move_pts(data, pt_x, pt_y) == 0)
			render_pl_direction(data, data->sprite.pl_t, x, y);
		else
			render_pl_direction(data, data->sprite.pl_t_r, x, y);
	}
}
