/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <glecler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:28:06 by glecler           #+#    #+#             */
/*   Updated: 2019/11/30 17:34:37 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void		ft_free_xpm(t_var *var, t_textures textures)
{
	mlx_destroy_image(var->mlx.mlx_ptr, textures.main_menu);
	mlx_destroy_image(var->mlx.mlx_ptr, textures.menu);
	mlx_destroy_image(var->mlx.mlx_ptr, textures.menu_blanc);
	mlx_destroy_image(var->mlx.mlx_ptr, textures.jouer);
	mlx_destroy_image(var->mlx.mlx_ptr, textures.jouer_blanc);
	mlx_destroy_image(var->mlx.mlx_ptr, textures.quitter);
	mlx_destroy_image(var->mlx.mlx_ptr, textures.quitter_blanc);
}

void		ft_mlx_erase_screen(t_var *var)
{
	ft_put_image(var, var->black_screen,
		ft_mlx_img_dimensions(0, 0, 960, 600));
	mlx_put_image_to_window(var->mlx.mlx_ptr,
		var->mlx.win_ptr, var->mlx.img_ptr, 0, 0);
}

void		ft_free_var(t_var *var)
{
	int i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(var->mlx.mlx_ptr, (var->wall_texture[i]).img_ptr);
		i++;
	}
	i = 0;
	while (var->map[i])
	{
		free(var->map[i]);
		i++;
	}
	free(var->map);
}

void		ft_init_mlx(t_var *var)
{
	if (!(var->mlx.mlx_ptr = mlx_init()))
	{
		ft_putstr("mlx_init error\n");
		exit(0);
	}
	if (!(var->mlx.win_ptr = mlx_new_window(var->mlx.mlx_ptr, SIZE_X, SIZE_Y,
		"Wolf3D")))
	{
		ft_putstr("mlx_new_window error\n");
		exit(0);
	}
	if (!(var->mlx.img_ptr = mlx_new_image(var->mlx.mlx_ptr, SIZE_X, SIZE_Y)))
	{
		ft_putstr("mlx_new_image error\n");
		exit(0);
	}
	if (!(var->mlx.img_addr = mlx_get_data_addr(var->mlx.img_ptr,
		&(var->mlx.bpp), &(var->mlx.s_l), &(var->mlx.endian))))
	{
		ft_putstr("mlx_get_data_addr error\n");
		exit(0);
	}
}

void		ft_clean_quit(t_textures s, t_var *var, t_player *pl)
{
	int i;

	i = 0;
	ft_free_xpm(var, s);
	ft_free_var(var);
	while (i < var->y_max)
	{
		free(var->m[i]);
		i++;
	}
	free(var->m);
	mlx_destroy_image(var->mlx.mlx_ptr, var->mlx.img_ptr);
	mlx_destroy_window(var->mlx.mlx_ptr, var->mlx.win_ptr);
	(void)pl;
	exit(0);
}
