/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <glecler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:28:06 by glecler           #+#    #+#             */
/*   Updated: 2019/11/30 17:33:29 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int		ft_get_key(int key, t_hook_param *hook_param)
{
	if (key == 53)
		ft_clean_quit(hook_param->textures, hook_param->var, hook_param->pl);
	if (hook_param->var->menu == 0)
	{
		if (key == FORWARD)
			hook_param->var->key.forw = 1;
		else if (key == BACK)
			hook_param->var->key.back = 1;
		else if (key == RIGHT)
			hook_param->var->key.right = 1;
		else if (key == LEFT)
			hook_param->var->key.left = 1;
	}
	return (0);
}

int		ft_get_key_release(int key, t_hook_param *hook_param)
{
	if (hook_param->var->menu == 0)
	{
		if (key == FORWARD)
			hook_param->var->key.forw = 0;
		else if (key == BACK)
			hook_param->var->key.back = 0;
		else if (key == RIGHT)
			hook_param->var->key.right = 0;
		else if (key == LEFT)
			hook_param->var->key.left = 0;
	}
	return (0);
}

int		ft_get_mouse(int button, int x, int y, void *param)
{
	t_hook_param *hook_param;

	hook_param = param;
	if (x >= 180 && x <= 780 && y >= 260 && y <= 310 && button == 1
		&& hook_param->var->menu == 1)
	{
		hook_param->var->menu = 0;
		return (0);
	}
	if (x >= 180 && x <= 780 && y >= 320 && y <= 370 && button == 1
		&& hook_param->var->menu == 1)
		ft_clean_quit(hook_param->textures, hook_param->var, hook_param->pl);
	if (x >= 750 && x <= 929 && y >= 30 && y <= 80 && button == 1
		&& hook_param->var->menu == 0)
	{
		hook_param->var->menu = 1;
		ft_menu(hook_param->var, hook_param->textures);
	}
	return (0);
}

int		ft_get_motion(int x, int y, void *param)
{
	t_hook_param *hook_param;

	hook_param = param;
	if (hook_param->var->menu == 1)
	{
		if (x >= 180 && x <= 780 && y >= 260 && y <= 310)
			ft_put_image(hook_param->var, hook_param->textures.jouer_blanc,
				ft_mlx_img_dimensions(180, 260, 600, 50));
		else
			ft_put_image(hook_param->var, hook_param->textures.jouer,
				ft_mlx_img_dimensions(180, 260, 600, 50));
		if (x >= 180 && x <= 780 && y >= 320 && y <= 370)
			ft_put_image(hook_param->var, hook_param->textures.quitter_blanc,
				ft_mlx_img_dimensions(180, 320, 600, 50));
		else
			ft_put_image(hook_param->var, hook_param->textures.quitter,
				ft_mlx_img_dimensions(180, 320, 600, 50));
	}
	else
		ft_motion_menu_zero(x, y, hook_param);
	mlx_put_image_to_window(hook_param->var->mlx.mlx_ptr,
		hook_param->var->mlx.win_ptr, hook_param->var->mlx.img_ptr, 0, 0);
	return (0);
}

int		ft_exit_hook(int x, int y, void *param)
{
	t_hook_param *hook_param;

	hook_param = param;
	x = 0;
	y = 0;
	exit(0);
	return (0);
}
