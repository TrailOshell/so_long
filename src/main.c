/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:13:10 by tsomchan          #+#    #+#             */
/*   Updated: 2024/06/19 22:34:35 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

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
	data->moves = 0;
	return (data);
}

int	read_map(char **argv, t_data *data)
{
	int		fd;

	printf("open(argv[1], O_RDONLY) = \"%s\"\n", argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_and_exit(data, "ERROR! fd error\n");
	if (sl_strrncmp(argv[1], ".ber", 4))
		error_and_exit(data, "ERROR! only .ber file is allowed\n");
	get_next_row(data, fd);
	set_map(data, data->node);
	if (data->node)
		printf("node is true\n");
	flood_fill(data);
	return (1);
}

int	load_textures(t_data *data)
{
	int	size;

	size = SIZE;
	data->m_sprites.brick = mlx_xpm_file_to_image(data->mlx, \
			BRICK_TILE, &size, &size);
	data->m_sprites.snow = mlx_xpm_file_to_image(data->mlx, \
			SNOW_TILE, &size, &size);
	return (1);
}

void	render_tile(t_data *data, t_map_sprite m_sprites, int x, int y)
{
	if (data->map->grid[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->win, \
			m_sprites.brick, x * SIZE, y * SIZE);
	//else if (iswalkable(data->map->grid[y][x]) == 1 \
	//	|| data->map->grid[y][x] == 'P')
	//	mlx_put_image_to_window(data->mlx, data->win, \
	//		m_sprites.snow, x * SIZE, y * SIZE);
}
/*
	t_map_sprite	m_sprites;

	m_sprites = data->map->sprites;
*/

void	render_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map->grid[y])
	{
		x = 0;
		while (data->map->grid[y][x])
		{
			render_tile(data, data->m_sprites, x, y);
			x++;
		}
		y++;
	}
}

void	render_collect(t_data *data, t_collect *collect)
{
	while (collect)
	{
		mlx_put_image_to_window(data->mlx, data->win, data->m_sprites.snow, \
			collect->x * SIZE, collect->y * SIZE);
		collect = collect->next;
	}
}

void	render_objects(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->m_sprites.snow, \
		data->player->x * SIZE, data->player->y * SIZE);
	mlx_put_image_to_window(data->mlx, data->win, data->m_sprites.snow, \
		data->exit->x * SIZE, data->exit->y * SIZE);
	if (data->collect)
		printf("true\n");
	render_collect(data, data->collect);
	//int	x;
	//int	y;

	//y = 0;
	//while (data->map->grid[y])
	//{
	//	x = 0;
	//	while (data->map->grid[y][x])
	//	{
	//		render_tile(data, data->map->sprites, x, y);
	//		x++;
	//	}
	//	y++;
	//}
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
	data->win = mlx_new_window(data->mlx, \
		data->map->n_col * SIZE, data->map->n_row * SIZE, "so_long");
	if (!data->win)
		return (free(data->mlx), 1);
	load_textures(data);
	render_objects(data);
	render_map(data);
	mlx_hook(data->win, KEYPRESS, (1L << 0), &on_keypress, data);
	mlx_hook(data->win, DESTROYNOTIFY, (1L << 2), &on_game_exit, data);
	mlx_loop(data->mlx);
	return (0);
}

/*
	void *mlx_xpm_file_to_image(void *mlx, char *filename,
		int *width, int *height);

	img_ptr = malloc();	
	img_ptr = mlx_xpm_file_to_image(void *mlx, char *filename,
		int *width, int *height);
*/

/*
	int mlx_put_image_to_window(void *mlx, void *win,
		void *img_ptr, int x, int y);
*/

/* read_map() debug
int	read_map(char **argv, t_data *data)
{
	int		fd;

	printf("open(argv[1], O_RDONLY) = \"%s\"\n", argv[1]);
	fd = open(argv[1], O_RDONLY);
	printf("fd = %d\n", fd);
	if (fd < 0)
		error_and_exit(data, "ERROR! fd error\n");
	if (sl_strrncmp(argv[1], ".ber", 4))
		error_and_exit(data, "ERROR! only .ber file is allowed\n");
	printf("next\n");
	printf("data->node->line = %s\n", data->node->line);
	printf("data->node->line = %s\n", data->node->next->line);
	printf("data->node->line = %s\n", data->node->next->next->line);
	get_next_row(data, fd);
	set_map(data, &data->map->grid, data->node);
	flood_fill(data, data->map);
	return (1);
}
*/