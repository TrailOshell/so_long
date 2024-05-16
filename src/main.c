/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:13:10 by tsomchan          #+#    #+#             */
/*   Updated: 2024/05/05 17:13:11 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"
//#include "../inc/so_long.h"

t_map	*start_map(t_map *map)
{
	if (!map)
		map = malloc(sizeof(t_map));
	map->n_col = 0;
	map->n_row = 0;
	return (map);
}

t_data	*start_data(t_data *data)
{
	if (!data)
		data = malloc(sizeof(t_data));
	data->mlx_ptr = mlx_init();
	printf("n\n");
	data->map = start_map(data->map);
	data->player = malloc(sizeof(t_player));
	data->exit = malloc(sizeof(t_exit));
	data->collect = malloc(sizeof(t_collect));
	return (data);
}

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	//if (keysym == KEY_UP || keysym == KEY_W)
	//if (keysym == KEY_LEFT || keysym == KEY_A)
	//if (keysym == KEY_RIGHT || keysym == KEY_D)
	//if (keysym == KEY_DOWN || keysym == KEY_S)
	if (keysym == KEY_Q || keysym == KEY_ESC)
	{
		on_destroy(data);
		exit(0);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		error_and_exit();
	data = NULL;
	data = start_data(data);
	if (!data->mlx_ptr)
		return (1);
	read_map(argv, data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1920, 1080, "so_long");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), 1);
	mlx_hook(data->win_ptr, KEYPRESS, (1L << 0), &on_keypress, data);
	mlx_hook(data->win_ptr, DESTROYNOTIFY, (1L << 2), &on_destroy, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

/*
	void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);

	img_ptr = malloc();	
	img_ptr = mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
*/

/*
	int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
*/