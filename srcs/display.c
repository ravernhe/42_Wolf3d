/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravernhe <ravernhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:28:06 by ravernhe          #+#    #+#             */
/*   Updated: 2019/11/30 17:33:29 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	menu_button_in_game(t_var *var, t_player *player, t_surf s)
{
	int			x_y[2];

	x_y[0] = var->sdl.event.button.x;
	x_y[1] = var->sdl.event.button.y;
	sdl_clean_screen(var->sdl.render);
	print_screen(var, player);
	if (x_y[0] >= 750 && x_y[0] <= 929 && x_y[1] >= 30 && x_y[1] <= 80)
	{
		put_surface(var, s.menu_o, create_sdl_rect(750, 30, 0, 0));
		SDL_RenderPresent(var->sdl.render);
		if (var->on == 0)
		{
			var->menu_is_act = 0;
			sdl_clean_screen(var->sdl.render);
			ft_menu(var, player, s, 1);
		}
	}
	else
		put_surface(var, s.menu, create_sdl_rect(750, 30, 0, 0));
}

void	display_3(t_var *var, t_player *pl, t_surf s)
{
	if (var->sdl.event.type == SDL_QUIT)
		ft_clean_quit(s, var, pl);
	else if (var->sdl.event.key.keysym.sym == SDLK_ESCAPE)
	{
		ft_clean_quit(s, var, pl);
	}
	else if (var->sdl.event.type == SDL_KEYDOWN && var->menu_is_act == 1)
		ft_move(var->sdl.event.key.keysym.sym, pl, var->sdl.render, var);
	if (var->sdl.event.type == SDL_MOUSEMOTION && (var->menu_is_act == 1))
	{
		var->on = 1;
		menu_button_in_game(var, pl, s);
	}
	else if (var->sdl.event.type == SDL_MOUSEBUTTONDOWN \
					&& (var->menu_is_act == 1))
	{
		var->on = 0;
		menu_button_in_game(var, pl, s);
	}
}

void	display_2(t_var *var, t_player *pl, int *token, t_surf s)
{
	*token = 0;
	var->menu_is_act = 0;
	var->on = 0;
	ft_menu(var, pl, s, 0);
}

void	loadbmp(t_surf *s)
{
	if (!(s->main_menu = SDL_LoadBMP("./assets/main_menu.bmp")))
		exit(0);
	if (!(s->dirt_bg = SDL_LoadBMP("./assets/dirt_bg.bmp")))
		exit(0);
	if (!(s->menu = SDL_LoadBMP("./assets/menu.bmp")))
		exit(0);
	if (!(s->menu_o = SDL_LoadBMP("./assets/menu_o.bmp")))
		exit(0);
	if (!(s->done = SDL_LoadBMP("./assets/done.bmp")))
		exit(0);
	if (!(s->done_o = SDL_LoadBMP("./assets/done_o.bmp")))
		exit(0);
	if (!(s->reset = SDL_LoadBMP("./assets/reset.bmp")))
		exit(0);
	if (!(s->reset_o = SDL_LoadBMP("./assets/reset_o.bmp")))
		exit(0);
}

void	display(t_var *var, t_player *pl)
{
	int		token;
	t_surf	s;

	loadbmp(&s);
	display_2(var, pl, &token, s);
	while (SDL_WaitEvent(&var->sdl.event))
	{
		if (var->menu_is_act == 0 || var->menu_is_act == 2)
		{
			if (var->sdl.event.type == SDL_MOUSEMOTION)
			{
				var->on = 1;
				ft_menu(var, pl, s, 1);
			}
			else if (var->sdl.event.type == SDL_MOUSEBUTTONDOWN)
			{
				var->on = 0;
				ft_menu(var, pl, s, 1);
			}
		}
		display_3(var, pl, s);
		if (var->menu_is_act == 2)
			key_gestion(var, pl, s);
	}
}
