/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravernhe <ravernhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:28:06 by ravernhe          #+#    #+#             */
/*   Updated: 2019/11/30 17:34:37 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void		freeloadbmp(t_surf s)
{
	SDL_FreeSurface(s.main_menu);
	SDL_FreeSurface(s.dirt_bg);
	SDL_FreeSurface(s.menu);
	SDL_FreeSurface(s.menu_o);
	SDL_FreeSurface(s.done);
	SDL_FreeSurface(s.done_o);
	SDL_FreeSurface(s.reset);
	SDL_FreeSurface(s.reset_o);
}

SDL_Rect	create_sdl_rect(int x, int y, int w, int h)
{
	SDL_Rect r;

	r.x = x;
	r.y = y;
	r.w = w;
	r.h = h;
	return (r);
}

void		sdl_clean_screen(SDL_Renderer *rend)
{
	SDL_SetRenderDrawColor(rend, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(rend);
}

/*
** destroy/free render + destroy/free window
*/

void		free_var(t_var *v)
{
	int i;

	i = 0;
	while (i < 4)
	{
		SDL_FreeSurface(v->wall_texture[i]);
		i++;
	}
	i = 0;
	while (i < 41)
	{
		SDL_FreeSurface(v->key_texture[i]);
		i++;
	}
	i = 0;
	while (v->map[i])
	{
		free(v->map[i]);
		i++;
	}
	free(v->map);
}

void		ft_clean_quit(t_surf s, t_var *v, t_player *pl)
{
	int i;

	i = 0;
	free_var(v);
	freeloadbmp(s);
	while (i < v->y_max)
	{
		free(v->m[i]);
		i++;
	}
	free(v->m);
	SDL_DestroyWindow(v->sdl.window);
	SDL_DestroyRenderer(v->sdl.render);
	(void)pl;
	SDL_Quit();
	exit(0);
}
