/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomchan <tsomchan@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:32:03 by tsomchan          #+#    #+#             */
/*   Updated: 2025/03/18 18:24:49 by tsomchan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

# include "mlx.h"
# include "get_next_line.h"

// color
# define RESET "\033[0;39m"
# define GRAY "\033[0;90m"
# define RED "\033[0;91m"
# define GREEN "\033[0;92m"
# define YELLOW "\033[0;93m"
# define BLUE "\033[0;94m"
# define MAGENTA "\033[0;95m"
# define CYAN "\033[0;96m"
# define WHITE "\033[0;97m"

// tile size
# ifndef SIZE
#  define SIZE				64
//#  define SIZE				128
# endif

# define PTH_16				"sprites/16/"
# define PTH_32				"sprites/32/"
# define PTH_64				"sprites/64/"
# define PTH_128			"sprites/128/"

// map sprites path
# define BRICK_S			"brick south.xpm"
# define BRICK_M			"brick middle.xpm"
# define SNOW				"snow.xpm"

// object sprites path
# define MATCH				"bg/match box bg.xpm"
# define EXIT_OFF			"bg/furnace cold bg.xpm"
# define EXIT_ON			"bg/furnace hot bg.xpm"

// patrol sprites path

# define PT_S_UP			"bg/turkey bg.xpm"
# define PT_S_DOWN			"bg/turkey bg.xpm"
# define PT_S_LEFT			"bg/turkey bg.xpm"
# define PT_S_RIGHT			"bg/turkey bg.xpm"
# define PT_S_R_UP			"bg/turkey ready bg.xpm"
# define PT_S_R_DOWN		"bg/turkey ready bg.xpm"
# define PT_S_R_LEFT		"bg/turkey ready bg.xpm"
# define PT_S_R_RIGHT		"bg/turkey ready bg.xpm"
# define PT_M_UP			"bg/turkey match box bg.xpm"
# define PT_M_DOWN			"bg/turkey match box bg.xpm"
# define PT_M_LEFT			"bg/turkey match box bg.xpm"
# define PT_M_RIGHT			"bg/turkey match box bg.xpm"
# define PT_M_R_UP			"bg/turkey ready match box bg.xpm"
# define PT_M_R_DOWN		"bg/turkey ready match box bg.xpm"
# define PT_M_R_LEFT		"bg/turkey ready match box bg.xpm"
# define PT_M_R_RIGHT		"bg/turkey ready match box bg.xpm"

// player sprites path
# define PL_UP				"bg/match girl up bg snow.xpm"
# define PL_DOWN			"bg/match girl down bg snow.xpm"
# define PL_LEFT			"bg/match girl left bg snow.xpm"
# define PL_RIGHT			"bg/match girl right bg snow.xpm"
# define PL_S_UP			"bg/match girl up bg snow.xpm"
# define PL_S_DOWN			"bg/match girl down bg snow.xpm"
# define PL_S_LEFT			"bg/match girl left bg snow.xpm"
# define PL_S_RIGHT			"bg/match girl right bg snow.xpm"
# define PL_B_UP			"bg/match girl up bg brick.xpm"
# define PL_B_DOWN			"bg/match girl down bg brick.xpm"
# define PL_B_LEFT			"bg/match girl left bg brick.xpm"
# define PL_B_RIGHT			"bg/match girl right bg brick.xpm"
# define PL_M_UP			"bg/match girl up bg match box.xpm"
# define PL_M_DOWN			"bg/match girl down bg match box.xpm"
# define PL_M_LEFT			"bg/match girl left bg match box.xpm"
# define PL_M_RIGHT			"bg/match girl right bg match box.xpm"
# define PL_C_UP			"bg/match girl up bg furnace cold.xpm"
# define PL_C_DOWN			"bg/match girl down bg furnace cold.xpm"
# define PL_C_LEFT			"bg/match girl left bg furnace cold.xpm"
# define PL_C_RIGHT			"bg/match girl right bg furnace cold.xpm"
# define PL_H_UP			"bg/match girl up bg furnace hot.xpm"
# define PL_H_DOWN			"bg/match girl down bg furnace hot.xpm"
# define PL_H_LEFT			"bg/match girl left bg furnace hot.xpm"
# define PL_H_RIGHT			"bg/match girl right bg furnace hot.xpm"
# define PL_T_UP			"bg/match girl up bg turkey.xpm"
# define PL_T_DOWN			"bg/match girl down bg turkey.xpm"
# define PL_T_LEFT			"bg/match girl left bg turkey.xpm"
# define PL_T_RIGHT			"bg/match girl right bg turkey.xpm"
# define PL_T_R_UP			"bg/match girl up bg turkey ready.xpm"
# define PL_T_R_DOWN		"bg/match girl down bg turkey ready.xpm"
# define PL_T_R_LEFT		"bg/match girl left bg turkey ready.xpm"
# define PL_T_R_RIGHT		"bg/match girl right bg turkey ready.xpm"
# define PL_T_M_UP			"bg/match girl up bg turkey match box.xpm"
# define PL_T_M_DOWN		"bg/match girl down bg turkey match box.xpm"
# define PL_T_M_LEFT		"bg/match girl left bg turkey match box.xpm"
# define PL_T_M_RIGHT		"bg/match girl right bg turkey match box.xpm"
# define PL_T_M_R_UP		"bg/match girl up bg turkey ready match box.xpm"
# define PL_T_M_R_DOWN		"bg/match girl down bg turkey ready match box.xpm"
# define PL_T_M_R_LEFT		"bg/match girl left bg turkey ready match box.xpm"
# define PL_T_M_R_RIGHT		"bg/match girl right bg turkey ready match box.xpm"
//# define PL_OVER			"bg/match girl over.xpm"

typedef struct s_map_sprite
{
	void	*brick_s;
	void	*brick_m;
	void	*snow;
}	t_map_sprite;

typedef struct s_pl_sprite
{
	void	*up;
	void	*down;
	void	*left;
	void	*right;
}	t_pl_sprite;

typedef struct s_pt_sprite
{
	void	*up;
	void	*down;
	void	*left;
	void	*right;
}	t_pt_sprite;

typedef struct s_obj_sprite
{
	void	*collectible;
	void	*exit_off;
	void	*exit_on;
}	t_obj_sprite;

typedef struct s_sprite
{
	t_map_sprite	m;
	t_obj_sprite	o;
	t_pl_sprite		pl;
	t_pl_sprite		pl_s;
	t_pl_sprite		pl_b;
	t_pl_sprite		pl_m;
	t_pl_sprite		pl_c;
	t_pl_sprite		pl_h;
	t_pl_sprite		pl_t;
	t_pl_sprite		pl_t_r;
	t_pl_sprite		pl_t_m;
	t_pl_sprite		pl_t_m_r;
	t_pt_sprite		pt;
	t_pt_sprite		pt_s;
	t_pt_sprite		pt_s_r;
	t_pt_sprite		pt_m;
	t_pt_sprite		pt_m_r;
}	t_sprite;

typedef struct s_node
{
	struct s_node	*next;
	char			*line;
	int				x;
	int				y;
}	t_node;

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

typedef struct s_player
{
	int			x;
	int			y;
	t_pl_sprite	sprites;
}	t_player;

typedef struct s_patrol
{
	int				x;
	int				y;
	float			move_spd;
	float			move_pts;
	char			facing;
	int				steps_needed;
	int				is_on_collect;
	t_pt_sprite		sprites;
	struct s_patrol	*next;
}	t_patrol;

typedef struct s_map
{
	int				n_row;
	int				n_col;
	int				n_player;
	int				n_exit;
	int				n_collect;
	int				n_patrol;
	char			**grid;
}	t_map;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_map			*map;
	t_node			*node;
	t_player		*player;
	t_patrol		*patrol;
	t_exit			*exit;
	t_collect		*collect;
	int				moves;
	t_sprite		sprite;
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
# define KEY_SPACE 			32
# define KEY_H				104
# define KEY_Q				113
# define KEY_ESC			65307

// main.c
t_map	*start_map(t_map *map);

// util.c
size_t	sl_strlen(char *s);
char	*sl_strdup(char *s);
int		sl_strrncmp(char *s1, char *s2, size_t n);
char	*sl_strjoin(char *s1, char *s2);
// sl_itoa.c
char	*sl_itoa(int n);
// is_conditions.c
int		isvalidchar(char c);
int		iswalkable(char c);
int		ispatrolable(char c);

// error.c
void	error_and_exit(t_data *data, char *msg);
// free.c
void	free_map(t_map **map);
void	free_collect(t_collect **collect);
void	free_node(t_node **node);
void	free_stuff(t_data *data);
// color.c
void	set_color(char *color);
void	color_from_char(char c);
// debug.c
void	write_grid(char **grid);
void	write_value(char *msg, int int_val);
void	write_color(char *msg, char *color);
void	write_color_exit(t_data *data, char *msg, char *color);
// debug_pathfinding.c
void	debug_facing_step(int up, int down, int left, int right);
void	debug_pathfinding(int up, int down, int left, int right);

// get_next_row.c
void	get_next_row(t_data *data, int fd);
// line.c
void	add_line(t_node **node, char *line);
char	*line_dupe(char *line);
char	*line_copy(char *copy, char *line);
// grid.c
char	**new_map(t_map *map);
char	**dupe_map(t_map *map);
// set_map.c
void	set_map(t_data *data, t_node *node);
// check_map_input.c
int		check_map_size(t_data *data);
int		check_map_by_lines(t_data *data, char **grid);
int		check_map_enclosed_walls(t_data *data, char **grid);
int		check_map_chars_count(t_data *data);
// set_object.c
int		set_player(t_player *player, int x, int y);
int		set_exit(t_exit *exit, int x, int y);
int		add_collectible(t_collect **collect, int x, int y);
int		add_patrol(t_patrol **patrol, int x, int y);
// flood_fill.c
int		flood_fill(t_data *data);

// sprites.c
void	*load_a_sprite(t_data *data, char *filename);
void	load_sprites(t_data *data);
// free_sprites.c
void	free_pl_sprites(t_data *data);
void	free_pt_sprites(t_data *data);
void	free_sprites(t_data *data);
// render.c
void	render_map(t_data *data);
void	render_tile(t_data *data, int x, int y);
void	render_pl_direction(t_data *data, t_pl_sprite player, int x, int y);
void	render_player(t_data *data, int x, int y);
void	render_patrol(t_data *data);
void	render_objects(t_data *data);
// render_pl_front_of_pt.c
void	render_pl_front_of_pt(t_data *data, int x, int y);

// mlx_events.c
int		game_exit(t_data *data);
int		on_keypress(int keysym, t_data *data);
// input.c
void	player_move(int x, int y, t_data *data);
void	player_wait(t_data *data);
void	show_help(void);

// patrol.c
void	patroling(t_data *data);
// pathfinding.c
int		pathfinding(char **grid, t_patrol *patrol);
char	set_next_step(int up, int down, int left, int right);

#endif
