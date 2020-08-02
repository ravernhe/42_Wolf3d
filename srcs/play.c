/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <glecler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:28:06 by glecler           #+#    #+#             */
/*   Updated: 2019/11/30 17:34:22 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int		ft_col(int **map, double x, double y)
{
	if (map[(int)(y / BSD)][(int)(x / BSD)] == 1)
		return (0);
	return (1);
}

void	ft_forward(t_player *pl, double angle, int speed, int **map)
{
	angle = (angle - 30) * RAD;
	if (cos(angle) > 0)
	{
		if (ft_col(map, pl->pos.x + (speed * fabs(cos(angle))), pl->pos.y))
			pl->pos.x += speed * fabs(cos(angle));
	}
	else if (cos(angle) < 0)
	{
		if (ft_col(map, pl->pos.x + (-1 * (speed * fabs(cos(angle)))),
			pl->pos.y))
			pl->pos.x += -1 * (speed * fabs(cos(angle)));
	}
	if (sin(angle) > 0)
	{
		if (ft_col(map, pl->pos.x, pl->pos.y + (-1 * (speed *
			fabs(sin(angle))))))
			pl->pos.y += -1 * (speed * fabs(sin(angle)));
	}
	else if (sin(angle) < 0)
	{
		if (ft_col(map, pl->pos.x, pl->pos.y + (speed * fabs(sin(angle)))))
			pl->pos.y += speed * fabs(sin(angle));
	}
}

void	ft_backward(t_player *pl, double angle, int speed, int **map)
{
	angle = (angle - 30) * RAD;
	if (cos(angle) > 0)
	{
		if (ft_col(map, pl->pos.x - (speed * fabs(cos(angle))), pl->pos.y))
			pl->pos.x -= speed * fabs(cos(angle));
	}
	else if (cos(angle) < 0)
	{
		if (ft_col(map, pl->pos.x - (-1 * (speed * fabs(cos(angle)))),
			pl->pos.y))
			pl->pos.x -= -1 * (speed * fabs(cos(angle)));
	}
	if (sin(angle) > 0)
	{
		if (ft_col(map, pl->pos.x, pl->pos.y - (-1 * (speed *
			fabs(sin(angle))))))
			pl->pos.y -= -1 * (speed * fabs(sin(angle)));
	}
	else if (sin(angle) < 0)
	{
		if (ft_col(map, pl->pos.x, pl->pos.y - (speed * fabs(sin(angle)))))
			pl->pos.y -= speed * fabs(sin(angle));
	}
}

int		ft_play(t_hook_param *hook_param)
{
	if (hook_param->var->menu == 0)
	{
		if (hook_param->var->key.forw == 1)
			ft_forward(hook_param->pl, hook_param->pl->angle, 10,
				hook_param->var->m);
		if (hook_param->var->key.back == 1)
			ft_backward(hook_param->pl, hook_param->pl->angle, 10,
				hook_param->var->m);
		if (hook_param->var->key.left == 1)
			hook_param->pl->angle += DIV_60_SIZE * 40.00;
		if (hook_param->var->key.right == 1)
			hook_param->pl->angle -= DIV_60_SIZE * 40.00;
		ft_mlx_erase_screen(hook_param->var);
		ft_raycasting(hook_param->var, hook_param->pl, hook_param->textures);
	}
	return (0);
}
