/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:50:58 by tsomchan          #+#    #+#             */
/*   Updated: 2024/07/06 01:24:32 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_exit(t_data *data)
{
	free_sprites(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_stuff(data);
	write_color("Game now exit\n", YELLOW);
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
	if (keysym == KEY_SPACE)
		player_wait(data);
	if (keysym == KEY_H)
		show_help();
	if (keysym == KEY_Q || keysym == KEY_ESC)
		write_color_exit(data, "Manually quit the game\n", YELLOW);
	return (0);
}

/*
	if (keysym == KEY_F)
		player_light_match(data);
*/
