/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:40:42 by tsomchan          #+#    #+#             */
/*   Updated: 2024/06/19 21:10:19 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

// int	walk_on_grid(char *c, t_data *data)
// {
// 	if (iswalkable(*c) == 0)
// 		return (0);
// 	if (*c == 'C')
// 		data->map->n_collect -= 1;
// 	else if (*c == 'E' && data->map->n_collect == 0)
// 		exit (1);
// 	*c = 'P';
// 	return (1);
// }

void	update_move(t_data *data, int cordx, int cordy)
{
	char	*str;

	data->map->grid[cordy][cordx] = '0';
	*c = 'P';
	data->player->x = cordx + x;
	data->player->y = cordy + y;
	data->moves += 1;
	write_value("Moves", data->moves);
	write(1, "\t", 1);
	write_value("Collectibles Left", data->map->n_collect);
	write(1, "\n", 1);
	write_grid(data->map->grid);
}

void	player_move(int x, int y, t_data *data)
{
	int		cordx;
	int		cordy;
	char	*c;

	cordx = data->player->x;
	cordy = data->player->y;
	c = &(data->map->grid[cordy + y][cordx + x]);
	if (iswalkable(*c))
	{
		if (*c == 'C')
			data->map->n_collect -= 1;
		else if (*c == 'E' && data->map->n_collect == 0)
			on_exit(data);
		else if (*c == 'E' && data->map->n_collect > 0)
			return ;
		update_move(data);
	}
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