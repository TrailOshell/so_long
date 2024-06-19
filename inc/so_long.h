/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:32:03 by tsomchan          #+#    #+#             */
/*   Updated: 2024/06/19 22:23:04 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

# include "mlx.h"
# include "get_next_line.h"

typedef struct s_err
{
	int	err_borders;
	int	err_exit;
	int	err_player;
	int	err_collect;
}	t_err;

typedef struct s_node
{
	struct s_node	*next;
	char			*line;
	int				x;
	int				y;
}	t_node;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_exit
{
	int	x;
	int	y;
}	t_exit;

typedef struct s_collect
{
	int					x;
	int					y;
	struct s_collect	*next;
}	t_collect;

typedef struct s_map
{
	int		n_row;
	int		n_col;
	int		n_player;
	int		n_exit;
	int		n_collect;
	int		n_enemy;
	char	**grid;
}	t_map;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		*map;
	t_node		*node;
	t_player	*player;
	t_exit		*exit;
	t_collect	*collect;
	int			moves;
}	t_data;

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

// main.c

// util.c
size_t	sl_strlen(char *s);
char	*sl_strdup(char *s);
int		sl_strrncmp(char *s1, char *s2, size_t n);
char	*sl_strjoin(char *s1, char *s2);

// sl_itoa.c
char	*sl_itoa(int n);

// error.c
void	error_and_exit(char *msg, t_data *data);

// free.c
void	free_map(t_map *map);
void	free_collect(t_collect *collect);
void	free_node(t_node *node);
void	free_stuff(t_data *data);

// debug.c
void	write_grid(char **grid);
void	write_value(char *msg, int int_val);

// is_conditions.c
int		isvalidchar(char c);
int		iswalkable(char c);

// get_next_row.c
void	get_next_row(t_data *data, int fd);

// line.c
void	add_line(t_node **node, char *line);
char	*line_dupe(char *line);
char	*line_copy(char *copy, char *line);

// grid.c
char	**new_grid(t_map *map);
char	**dupe_grid(char **map);

// set_map.c
void	set_map(t_data *data, t_node *node);

// set_object.c
int		set_player(t_player *player, int x, int y);
int		set_exit(t_exit *exit, int x, int y);
int		add_collectible(t_collect *collect, int x, int y);

// flood_fill.c
int		flood_fill(t_data *data);

// mlx_events.c
int		on_exit(t_data *data);
int		on_keypress(int keysym, t_data *data);

// input.c
void	player_move(int x, int y, t_data *data);

#endif
