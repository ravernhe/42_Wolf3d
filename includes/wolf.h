/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravernhe <ravernhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:28:06 by ravernhe          #+#    #+#             */
/*   Updated: 2019/12/02 14:55:02 by mamisdra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# define WALL '1'
# define COUL '0'
# define SPAWN '7'
# define BS_INT 128
# define BLOCK_SIZE 128.00
# define BS 128
# define BSD 128.00
# define SIZE_X 960
# define SIZE_Y 600
# define SIZE_X_2 480
# define SIZE_Y_2 300
# define SIZE_X_D 960.00
# define SIZE_Y_D 600.00
# define SIZE_X_D2 480.00
# define SIZE_Y_D2 300.00
# define ANGLE_BEGIN 30.00
# define RAD 0.0174532925
# define DIV_60_SIZE 0.0625
# include "../libft/includes/libft.h"
# include "SDL2/SDL.h"
# include "math.h"
# include <math.h>

typedef struct	s_key
{
	int			forw;
	int			back;
	int			right;
	int			left;
}				t_key;

typedef struct	s_sdl
{
	SDL_Window		*window;
	SDL_Renderer	*render;
	SDL_Event		event;
}				t_sdl;

typedef struct	s_rgb
{
	int			r;
	int			g;
	int			b;
	int			a;
}				t_rgb;

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
	int			x_max;
	int			y_max;
	int			select_key;
	int			i;
	int			texture_id;
	int			on;
	int			menu_is_act;
	int			key_id[4];
	int			**m;
	char		**map;
	t_sdl		sdl;
	t_pos		spawn;
	t_rgb		color;
	Uint32		*wall_uint[4];
	t_key		key;
	SDL_Surface	*wall_texture[4];
	SDL_Surface	*key_texture[41];
}				t_var;

typedef struct	s_player
{
	t_pos		pos;
	double		fov;
	double		angle;
	int			height;
}				t_player;

typedef struct	s_surf
{
	SDL_Surface *main_menu;
	SDL_Surface *dirt_bg;
	SDL_Surface *menu;
	SDL_Surface *menu_o;
	SDL_Surface *done;
	SDL_Surface *done_o;
	SDL_Surface *reset;
	SDL_Surface *reset_o;
}				t_surf;

/*
** main.c
*/

void			init_key_move(t_var *var);

/*
** display_tool_2.c
*/

int				launch_ray(t_player *pl, t_var *var, double al, double beta);

/*
** display_tool.c
*/
void			init_a_b_alpha(t_pos *a, t_pos *b, double *alpha);
void			print_screen(t_var *var, t_player *player);

/*
** menu_2.c
*/

void			buttons_menu_options(t_var *var, int i);
void			buttons_menu_play(t_var *var, int i);
void			change_key(t_var *var, t_player *player, t_surf s);
void			choose_key(t_var *var, t_player *player, t_surf s);

/*
** put_surface.c
*/

void			put_surface(t_var *var, SDL_Surface *s, SDL_Rect dimensions);

/*
** menu.c
*/

void			option_menu(int *x_y, t_var *var, t_player *player, t_surf s);
void			ft_menu(t_var *var, t_player *player, t_surf s, int t);
void			print_button(int *x_y, t_var *var, t_player *player, t_surf s);

/*
** menu_3.c
*/

double			dist_0_1(t_var *var, double alpha, double beta, t_pos b);
double			dist_1_0(t_var *var, double alpha, double beta, t_pos a);
int				change_texture_key(int nk);
void			put_image(t_var *var, char *name, SDL_Rect dimensions);
void			put_image_opt(t_var *var, int id, SDL_Rect dimensions);

/*
** move.c
*/

void			ft_move(int key, t_player *pla, SDL_Renderer *ren, t_var *var);

/*
** map_parse.c
*/

void			parsing_map(int fd, t_var *var);

/*
** display.c
*/

void			display(t_var *var, t_player *pl);

/*
** error.c
*/

void			ft_error(int i);

/*
** texture.c
*/

t_rgb			get_color_from_surface(Uint32 x);
Uint32			set_pixel_color(t_rgb c);
t_rgb			set_color(int r, int g, int b, int a);
void			open_wall_texture(t_var *var);

/*
** ft_init_sdl.c
*/

void			ft_init_sdl(t_var *var);

/*
** open_textures_buttons.c
*/

void			open_img_opt_button(t_var *var);

/*
** parse_check.c
*/

void			check_map(t_var *var, int ret, size_t nb_char, char *str);

/*
** sdl_tools.c
*/

SDL_Rect		create_sdl_rect(int x, int y, int w, int h);
void			sdl_clean_screen(SDL_Renderer *rend);
void			ft_clean_quit(t_surf s, t_var *v, t_player *pl);

/*
** key_gestion.c
*/

void			key_gestion(t_var *var, t_player *pl, t_surf s);

#endif
