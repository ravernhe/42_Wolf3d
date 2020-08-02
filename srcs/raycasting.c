/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <glecler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:28:06 by glecler           #+#    #+#             */
/*   Updated: 2019/11/30 17:33:23 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int		ft_launch_ray(t_player *player, t_var *var, double alpha,
	double beta)
{
	double		dist[2];
	t_pos		a;
	t_pos		b;

	ft_init_a_b_alpha(&a, &b, &alpha);
	if (sin(alpha))
		ft_intersec_1(&a, var, player, alpha);
	if (cos(alpha))
		ft_intersec_2(&b, var, player, alpha);
	ft_calc_dist(dist, player, a, b);
	if (dist[0] >= 0 && dist[1] >= 0)
	{
		if (dist[0] > dist[1])
			return (dist[1] * ft_dist_0_1(var, alpha, beta, b));
		else
			return (dist[0] * ft_dist_1_0(var, alpha, beta, a));
	}
	else if (dist[0] >= 0)
		return (dist[0] * ft_dist_1_0(var, alpha, beta, a));
	return (dist[1] * ft_dist_0_1(var, alpha, beta, b));
}

void	ft_calc_hei_column(t_var *var, t_inter *inter, t_player *player)
{
	inter->dist = ft_launch_ray(player, var, inter->alpha, inter->beta);
	inter->hei = BSI * 931 / (inter->dist + 1);
	inter->phw = SIZE_Y_2 - inter->hei / 2;
	inter->y_img = 0;
	if (inter->phw < 0)
	{
		inter->y_img = -1 * inter->phw;
		inter->phw = 0;
	}
}

void	ft_draw_floor(t_var *var, t_inter *inter)
{
	ft_set_rgb(var->rgb, 150, 150, 150);
	while (inter->phw < SIZE_Y)
	{
		ft_put_pixel_img(var, inter->plw, inter->phw, var->rgb);
		inter->phw++;
	}
}

void	ft_raycasting(t_var *var, t_player *player, t_textures textures)
{
	t_inter	inter;
	int		y_tmp;

	ft_init_inter_variables(&inter, player);
	while (inter.plw != SIZE_X)
	{
		ft_calc_hei_column(var, &inter, player);
		while (inter.phw < SIZE_Y_2 + inter.hei / 2 && inter.phw < SIZE_Y - 1)
		{
			y_tmp = (double)inter.y_img / (double)inter.hei * BSD;
			ft_get_rgb_from_img(var->wall_texture[var->texture_id],
				var->x_bloc, y_tmp, var->rgb);
			ft_put_pixel_img(var, inter.plw, inter.phw, var->rgb);
			inter.y_img++;
			inter.phw++;
		}
		ft_draw_floor(var, &inter);
		inter.alpha = inter.alpha - DIV_60_SIZE;
		inter.beta = inter.beta - DIV_60_SIZE;
		inter.plw++;
	}
	ft_put_image(var, textures.menu, ft_mlx_img_dimensions(750, 30, 179, 50));
	mlx_put_image_to_window(var->mlx.mlx_ptr, var->mlx.win_ptr,
		var->mlx.img_ptr, 0, 0);
}
