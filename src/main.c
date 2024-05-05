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

#include "so_long.h"

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
	(void)data;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 600, 400, "so_long");
	if (!data.win_ptr)
		return (free(data.mlx_ptr), 1);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask,
		&on_destroy, &data);
	mlx_loop(data.mlx_ptr);
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