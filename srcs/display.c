/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <glecler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:28:06 by glecler           #+#    #+#             */
/*   Updated: 2019/11/30 17:34:17 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	ft_menu(t_var *var, t_textures textures)
{
	ft_put_image(var, textures.main_menu,
		ft_mlx_img_dimensions(0, 0, 960, 600));
	ft_put_image(var, textures.jouer,
		ft_mlx_img_dimensions(180, 260, 600, 50));
	ft_put_image(var, textures.quitter,
		ft_mlx_img_dimensions(180, 320, 600, 50));
	mlx_put_image_to_window(var->mlx.mlx_ptr,
		var->mlx.win_ptr, var->mlx.img_ptr, 0, 0);
}

void	ft_display(t_var *var, t_player *pl)
{
	t_hook_param hook_param;

	hook_param.var = var;
	hook_param.pl = pl;
	ft_load_xpm(var, &(hook_param.textures));
	var->menu = 1;
	ft_menu(var, hook_param.textures);
	mlx_mouse_hook(var->mlx.win_ptr, ft_get_mouse, &hook_param);
	mlx_hook(var->mlx.win_ptr, 2, (1L << 0), ft_get_key, &hook_param);
	mlx_hook(var->mlx.win_ptr, 3, (1L << 1), ft_get_key_release, &hook_param);
	mlx_hook(var->mlx.win_ptr, 6, 0L, &ft_get_motion, &hook_param);
	mlx_hook(var->mlx.win_ptr, 17, 0L, ft_exit_hook, &hook_param);
	mlx_loop_hook(var->mlx.mlx_ptr, &ft_play, &hook_param);
	mlx_loop(var->mlx.mlx_ptr);
}
