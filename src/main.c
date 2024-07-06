/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:13:10 by tsomchan          #+#    #+#             */
/*   Updated: 2024/07/06 01:30:58 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*start_map(t_map *map)
{
	map = malloc(sizeof(t_map));
	map->n_col = 0;
	map->n_row = 0;
	map->n_collect = 0;
	map->n_exit = 0;
	map->n_player = 0;
	map->grid = NULL;
	return (map);
}

t_data	*start_data(t_data *data)
{
	if (!data)
		data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->map = start_map(data->map);
	data->node = NULL;
	data->player = malloc(sizeof(t_player));
	data->exit = malloc(sizeof(t_exit));
	data->collect = NULL;
	data->patrol = NULL;
	data->moves = 0;
	return (data);
}

int	read_map(char **argv, t_data *data)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_and_exit(data, "ERROR! fd error\n");
	if (sl_strrncmp(argv[1], ".ber", 4))
		error_and_exit(data, "ERROR! only .ber file is allowed\n");
	else if (sl_strrncmp(argv[1], "/.ber", 5) == 0 || argv[1][0] == '.')
		error_and_exit(data, "ERROR! hidden file not allowed\n");
	get_next_row(data, fd);
	set_map(data, data->node);
	flood_fill(data);
	write_color("Initial map\n", GREEN);
	write_grid(data->map->grid);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	data = start_data(data);
	if (argc != 2)
		error_and_exit(data, "ERROR! Input arguments not equal 2\n");
	if (!data->mlx)
		return (0);
	read_map(argv, data);
	load_sprites(data);
	data->win = mlx_new_window(data->mlx, \
		data->map->n_col * SIZE, data->map->n_row * SIZE, "so_long");
	if (!data->win)
		return (free(data->mlx), 1);
	render_map(data);
	render_patrol(data);
	render_player(data, 0, 0);
	show_help();
	mlx_hook(data->win, KEYPRESS, (1L << 0), &on_keypress, data);
	mlx_hook(data->win, DESTROYNOTIFY, (1L << 2), &game_exit, data);
	mlx_loop(data->mlx);
	return (0);
}
