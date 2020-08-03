/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravernhe <ravernhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:28:06 by ravernhe          #+#    #+#             */
/*   Updated: 2019/11/30 17:34:43 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

t_rgb	set_color(int r, int g, int b, int a)
{
	t_rgb c;

	c.r = r;
	c.g = g;
	c.b = b;
	c.a = a;
	return (c);
}

Uint32	set_pixel_color(t_rgb c)
{
	return ((c.a << 24) + (c.r << 16) + (c.g << 8) + (c.b << 0));
}

t_rgb	get_color_from_surface(Uint32 x)
{
	t_rgb c;

	c.a = x >> 24 & 255;
	c.r = x >> 16 & 255;
	c.g = x >> 8 & 255;
	c.b = x >> 0 & 255;
	return (c);
}

void	open_wall_texture(t_var *var)
{
	int		i;
	void	*tmp;

	i = 0;
	if (!(var->wall_texture[0] = SDL_LoadBMP("./assets/t1.bmp")))
		exit(0);
	if (!(var->wall_texture[1] = SDL_LoadBMP("./assets/t2.bmp")))
		exit(0);
	if (!(var->wall_texture[2] = SDL_LoadBMP("./assets/t3.bmp")))
		exit(0);
	if (!(var->wall_texture[3] = SDL_LoadBMP("./assets/t4.bmp")))
		exit(0);
	while (i < 4)
	{
		tmp = var->wall_texture[i]->pixels;
		var->wall_uint[i] = (Uint32 *)tmp;
		i++;
	}
}
