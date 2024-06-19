/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:50:58 by tsomchan          #+#    #+#             */
/*   Updated: 2024/06/19 21:45:52 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_exit(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_stuff(data);
	exit(1);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == KEY_UP || keysym == KEY_W)
		player_move(0, -1, data);
	if (keysym == KEY_LEFT || keysym == KEY_A)
		player_move(-1, 0, data);
	if (keysym == KEY_RIGHT || keysym == KEY_D)
		player_move(1, 0, data);
	if (keysym == KEY_DOWN || keysym == KEY_S)
		player_move(0, 1, data);
	if (keysym == KEY_Q || keysym == KEY_ESC)
		on_exit(data);
	return (0);
}
