/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:50:40 by glecler           #+#    #+#             */
/*   Updated: 2020/07/27 13:44:16 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# define BSI 128
# define BSD 128.00
# define SIZE_X 960
# define SIZE_Y 600
# define SIZE_X_2 480
# define SIZE_Y_2 300
# define SIZE_X_D 960.00
# define SIZE_Y_D 600.00
# define SIZE_X_D2 480.00
# define SIZE_Y_D2 300.00
# define LEFT 123
# define RIGHT 124
# define FORWARD 126
# define BACK 125
# define RAD 0.0174532925
# define DIV_60_SIZE 0.0625

# include "./libft/includes/libft.h"
# include <math.h>
# include "minilibx_macos/mlx.h"
# include <fcntl.h>

typedef struct	s_key
{
	int			forw;
	int			back;
	int			right;
	int			left;
}				t_key;

typedef struct	s_dimensions
{
	int x;
	int y;
	int width;
	int height;
}				t_dimensions;

typedef struct	s_mlx_img
{
	void	*img_ptr;
	char	*img_addr;
	int		bpp;
	int		endian;
	int		s_l;
}				t_mlx_img;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_addr;
	int		bpp;
	int		endian;
	int		s_l;
	int		event_button[2];
}				t_mlx;

typedef struct	s_pos
{
	double		x;
	double		y;
}				t_pos;

typedef struct	s_inter
{
	double		alpha;
	double		beta;
	int			hei;
	int			dist;
	int			y_img;
	int			plw;
	int			phw;

}				t_inter;

typedef struct	s_var
{
	int				x_max;
	int				y_max;
	int				texture_id;
	int				x_bloc;
	int				menu;
	int				**m;
	char			**map;
	t_mlx			mlx;
	t_pos			spawn;
	unsigned char	rgb[4];
	t_key			key;
	t_mlx_img		wall_texture[4];
	void			*black_screen;
}				t_var;

typedef struct	s_player
{
	t_pos		pos;
	double		fov;
	double		angle;
	int			height;
}				t_player;

typedef struct	s_textures
{
	void *main_menu;
	void *menu;
	void *menu_blanc;
	void *jouer;
	void *jouer_blanc;
	void *quitter;
	void *quitter_blanc;
}				t_textures;

typedef struct	s_hook_param
{
	t_var		*var;
	t_player	*pl;
	t_textures	textures;
}				t_hook_param;

/*
** main.c
*/

void			ft_init_key(t_key *key);
int				**ft_fill_map_struct(t_var var);
void			ft_player_data_set(t_player *player, t_var *var);
void			ft_is_first_char_zero(char *str);

/*
** tools.c
*/

void			ft_set_x_y(int *x_y, int x, int y);
void			ft_init_inter_variables(t_inter *inter, t_player *player);
void			ft_init_a_b_alpha(t_pos *a, t_pos *b, double *alpha);
void			ft_motion_menu_zero(int x, int y, t_hook_param *hook_param);
void			ft_set_rgb(unsigned char *rgb, unsigned char r,
					unsigned char g, unsigned char b);

/*
** raycasting.c
*/

int				ft_launch_ray(t_player *pl, t_var *var, double al,
					double beta);
void			ft_calc_hei_column(t_var *var, t_inter *inter,
					t_player *player);
void			ft_draw_floor(t_var *var, t_inter *inter);
void			ft_raycasting(t_var *var, t_player *player,
					t_textures textures);

/*
** raycasting_tool.c
*/

void			ft_intersec_1(t_pos *a, t_var *var, t_player *player,
					double alpha);
void			ft_intersec_2(t_pos *b, t_var *var, t_player *player,
					double alpha);
void			ft_calc_dist(double *dist, t_player *player, t_pos a,
					t_pos b);
double			ft_dist_0_1(t_var *var, double alpha, double beta, t_pos b);
double			ft_dist_1_0(t_var *var, double alpha, double beta, t_pos a);

/*
** display.c
*/

void			ft_display(t_var *var, t_player *pl);
void			ft_menu(t_var *var, t_textures s);

/*
** mlx_tools.c
*/

void			ft_free_xpm(t_var *var, t_textures textures);
void			ft_mlx_erase_screen(t_var *var);
void			ft_free_var(t_var *var);
void			ft_init_mlx(t_var *var);
void			ft_clean_quit(t_textures s, t_var *var, t_player *pl);

/*
** play.c
*/

int				ft_play(t_hook_param *hook_param);
void			ft_backward(t_player *pl, double angle, int speed, int **map);
void			ft_forward(t_player *pl, double angle, int speed, int **map);
int				ft_col(int **map, double x, double y);

/*
** map_parsing.c
*/

void			ft_parsing_map(int fd, t_var *var);
void			ft_init_var(t_var *var);
int				ft_check_char(char *buff);
/*
** event_hooks.c
*/

int				ft_get_key(int key, t_hook_param *hook_param);
int				ft_get_mouse(int button, int x, int y, void *param);
int				ft_get_motion(int x, int y, void *param);
int				ft_exit_hook(int x, int y, void *param);
int				ft_get_key_release(int key, t_hook_param *hook_param);

/*
** error.c
*/

void			ft_error(int i);

/*
** img_load.c
*/

void			ft_load_texture(t_var *var);
void			ft_load_xpm(t_var *var, t_textures *s);
void			ft_load_tex_addr(t_var *var);

/*
** parsing_check.c
*/

int				ft_check_space_between_digit(char *str);
int				ft_check_spawn(char *str);
void			ft_put_wall_around_the_map(int hei, int len, t_var *var);
void			ft_check_map(t_var *var, int ret, size_t nb_char, char *str);

/*
** img_tools.c
*/

t_dimensions	ft_mlx_img_dimensions(int x, int y, int w, int h);
void			ft_put_image(t_var *var, void *img_ptr, t_dimensions dim);
int				ft_put_pixel_img(t_var *var, int x, int y, unsigned char *rgb);
int				ft_get_rgb_from_img(t_mlx_img mlx_img, int x, int y,
					unsigned char *rgb);

#endif
