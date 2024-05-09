/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:29:56 by tsomchan          #+#    #+#             */
/*   Updated: 2024/05/05 17:29:57 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>

# include "mlx.h"

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	//void		*textures[5];
	t_map		*map;
}	t_data;

typedef struct s_map
{
	int	n_row;
	int	n_col;
	int	n_exit;
	int	n_collect;
	int	n_player;
	int	n_enemy;
}	t_map;

typedef struct s_err
{
	int	err_borders;
}	t_err;


//	X11 events 
# define KEYPRESS			2
# define DESTROYNOTIFY		17
# define EXPOSE				12

//# define KEYPRESSMASK	(1L<<0)

# define KEY_W				119
# define KEY_A				97
# define KEY_S				115
# define KEY_D				100 
# define KEY_UP  			65362
# define KEY_LEFT  			65361
# define KEY_RIGHT 			65363
# define KEY_DOWN  			65364 
# define KEY_Q				113
# define KEY_ESC			65307

#endif