/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <glecler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:28:06 by glecler           #+#    #+#             */
/*   Updated: 2019/11/30 17:33:16 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	ft_intersec_1(t_pos *a, t_var *var, t_player *player, double alpha)
{
	double xa;
	double ya;

	a->y = sin(alpha) > 0 ? (int)(player->pos.y / BSD) * BSD :
	(int)(player->pos.y / BSD) * BSD + BSD;
	xa = sin(alpha) > 0 ? 1.00 : -1.00;
	ya = sin(alpha) > 0 ? -BSD : BSD;
	a->x = (player->pos.y - a->y) / tan(alpha) + player->pos.x;
	xa *= BSD / tan(alpha);
	a->y = sin(alpha) > 0 ? a->y - 1 : a->y;
	while (a->y / BSD < var->y_max && a->x / BSD < var->x_max && a->y / BSD > 0
		&& a->x / BSD > 0 && (var->m[(int)(a->y / BSD)][(int)(a->x / BSD)] == 0
		|| var->m[(int)(a->y / BSD)][(int)(a->x / BSD)] == 7))
	{
		a->x += xa;
		a->y += ya;
	}
	a->y = sin(alpha) > 0 ? a->y + 1 : a->y + 0;
}

void	ft_intersec_2(t_pos *b, t_var *var, t_player *player, double alpha)
{
	double xa;
	double ya;

	b->x = cos(alpha) > 0 ? (int)(player->pos.x / BSD) * BSD + BSD : \
			(int)(player->pos.x / BSD) * BSD;
	xa = cos(alpha) > 0 ? BSD : -BSD;
	ya = cos(alpha) > 0 ? -1.00 : 1.00;
	b->y = player->pos.y + (player->pos.x - b->x) * tan(alpha);
	ya *= BSD * tan(alpha);
	b->x = cos(alpha) > 0 ? b->x : b->x - 1;
	while (b->y / BSD < var->y_max && b->x / BSD < var->x_max && b->y / BSD > 0
		&& b->x / BSD > 0 && (var->m[(int)(b->y / BSD)][(int)(b->x / BSD)] == 0
		|| var->m[(int)(b->y / BSD)][(int)(b->x / BSD)] == 7))
	{
		b->x += xa;
		b->y += ya;
	}
	b->x = cos(alpha) > 0 ? b->x : b->x + 1;
}

void	ft_calc_dist(double *dist, t_player *player, t_pos a, t_pos b)
{
	double f1;
	double f2;

	f1 = player->pos.x - a.x;
	f2 = player->pos.y - a.y;
	dist[0] = sqrt((f1 * f1) + (f2 * f2));
	f1 = player->pos.x - b.x;
	f2 = player->pos.y - b.y;
	dist[1] = sqrt((f1 * f1) + (f2 * f2));
}

double	ft_dist_0_1(t_var *var, double alpha, double beta, t_pos b)
{
	var->texture_id = cos(alpha) > 0 ? 0 : 1;
	var->x_bloc = (int)b.y % BSI;
	return (cos(beta * RAD));
}

double	ft_dist_1_0(t_var *var, double alpha, double beta, t_pos a)
{
	var->texture_id = sin(alpha) > 0 ? 2 : 3;
	var->x_bloc = (int)a.x % BSI;
	return (cos(beta * RAD));
}
