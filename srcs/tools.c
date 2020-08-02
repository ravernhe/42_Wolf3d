/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <glecler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 17:28:06 by glecler           #+#    #+#             */
/*   Updated: 2020/05/27 17:33:29 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	ft_set_x_y(int *x_y, int x, int y)
{
	x_y[0] = x;
	x_y[1] = y;
}

void	ft_init_inter_variables(t_inter *inter, t_player *player)
{
	inter->beta = 30.00;
	inter->plw = 0;
	inter->y_img = 0;
	inter->alpha = player->angle;
}

void	ft_set_rgb(unsigned char *rgb, unsigned char r, unsigned char g,
	unsigned char b)
{
	rgb[0] = r;
	rgb[1] = g;
	rgb[2] = b;
}

void	ft_init_a_b_alpha(t_pos *a, t_pos *b, double *alpha)
{
	a->x = 10000;
	a->y = 10000;
	b->x = 10000;
	b->y = 10000;
	*alpha = *alpha * RAD;
}

void	ft_motion_menu_zero(int x, int y, t_hook_param *hook_param)
{
	if (x >= 750 && x <= 929 && y >= 30 && y <= 80)
		ft_put_image(hook_param->var, hook_param->textures.menu_blanc,
			ft_mlx_img_dimensions(750, 30, 179, 50));
	else
		ft_put_image(hook_param->var, hook_param->textures.menu,
			ft_mlx_img_dimensions(750, 30, 179, 50));
}
