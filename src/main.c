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
	data->mlx_ptr = mlx_init();
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

int	rendering(void)
{
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = NULL;
	data = start_data(data);
	if (argc != 2)
		error_and_exit(data, "ERROR! Input arguments not equal 2\n");
	if (!data->mlx_ptr)
		return (0);
	read_map(argv, data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "so_long");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), 1);
	rendering();
	mlx_hook(data->win_ptr, KEYPRESS, (1L << 0), &on_keypress, data);
	mlx_hook(data->win_ptr, DESTROYNOTIFY, (1L << 2), &on_game_exit, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

/*
	void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
		int *width, int *height);

	img_ptr = malloc();	
	img_ptr = mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
		int *width, int *height);
*/

/*
	int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr,
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