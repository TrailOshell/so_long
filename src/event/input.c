/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:40:42 by tsomchan          #+#    #+#             */
/*   Updated: 2024/07/05 20:22:00 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	update_move(t_data *data, int x, int y, char *target_tile)
{
	data->map->grid[data->player->y][data->player->x] = '0';
	*target_tile = 'P';
	data->player->x += x;
	data->player->y += y;
	data->moves += 1;
	write_value("Moves", data->moves);
	write(1, "\t", 1);
	write_value("Collectibles Left", data->map->n_collect);
	write(1, "\n", 1);
}

void	player_move(int x, int y, t_data *data)
{
	char	*target_tile;

	target_tile = &(data->map->grid[data->player->y + y][data->player->x + x]);
	if (iswalkable(*target_tile))
	{
		if (*target_tile == 'C')
			data->map->n_collect -= 1;
		else if (*target_tile == 'E' && data->map->n_collect == 0)
		{
			write_color("Stage passed! 🎉\n", GREEN);
			on_game_exit(data);
		}
		else if (*target_tile == 'E' && data->map->n_collect > 0)
			return ;
		update_move(data, x, y, target_tile);
		patroling(data);
		write_grid(data->map->grid);
		render_tile(data, data->player->x - x, data->player->y - y);
		render_tile(data, data->player->x - x, data->player->y - y - 1);
		if (data->map->n_collect == 0)
			render_tile(data, data->exit->x, data->exit->y);
	}
	else if (*target_tile == 'T')
	{
		write_color("GAME OVER 💀\n", RED);
		on_game_exit(data);
	}
	render_player(data, x, y);
}

/* player_move() put this under -> c = &(data->map->grid[cordy + y][cordx + x]);
	if (iswalkable(data->map->grid[cordy + y][cordx + x]))
*/

/* old update_move() implementation
void	update_move(t_data *data)
{
	char	*str;

	write(1, "Moves: ", 7);
	str = sl_itoa(data->moves); write(1, str, sl_strlen(str)); free(str);
	write(1, "\t", 1);
	write(1, "Collectibles Left: ", 19);
	str = sl_itoa(data->map->n_collect); write(1, str, sl_strlen(str));
	free(str);
	write(1, "\n", 1);
	write_grid(data->map->grid);
}
*/