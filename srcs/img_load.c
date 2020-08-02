/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <glecler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:28:06 by glecler           #+#    #+#             */
/*   Updated: 2019/11/30 17:34:43 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	ft_load_tex_addr(t_var *var)
{
	if (!((var->wall_texture[0]).img_addr = mlx_get_data_addr(
		(var->wall_texture[0]).img_ptr, &(var->wall_texture[0]).bpp,
			&(var->wall_texture[0]).s_l, &(var->wall_texture[0]).endian)))
		exit(0);
	if (!((var->wall_texture[1]).img_addr = mlx_get_data_addr(
		(var->wall_texture[1]).img_ptr, &(var->wall_texture[1]).bpp,
			&(var->wall_texture[1]).s_l, &(var->wall_texture[1]).endian)))
		exit(0);
	if (!((var->wall_texture[2]).img_addr = mlx_get_data_addr(
		(var->wall_texture[2]).img_ptr, &(var->wall_texture[2]).bpp,
			&(var->wall_texture[2]).s_l, &(var->wall_texture[2]).endian)))
		exit(0);
	if (!((var->wall_texture[3]).img_addr = mlx_get_data_addr(
		(var->wall_texture[3]).img_ptr, &(var->wall_texture[3]).bpp,
			&(var->wall_texture[3]).s_l, &(var->wall_texture[3]).endian)))
		exit(0);
}

void	ft_load_texture(t_var *var)
{
	int		x_y[2];

	ft_set_x_y(x_y, 128, 128);
	if (!((var->wall_texture[0]).img_ptr = mlx_xpm_file_to_image(
		var->mlx.mlx_ptr, "./assets/wall1.xpm", &(x_y[0]), &(x_y[1]))))
		exit(0);
	if (!((var->wall_texture[1]).img_ptr = mlx_xpm_file_to_image(
		var->mlx.mlx_ptr, "./assets/wall2.xpm", &(x_y[0]), &(x_y[1]))))
		exit(0);
	if (!((var->wall_texture[2]).img_ptr = mlx_xpm_file_to_image(
		var->mlx.mlx_ptr, "./assets/wall3.xpm", &(x_y[0]), &(x_y[1]))))
		exit(0);
	if (!((var->wall_texture[3]).img_ptr = mlx_xpm_file_to_image(
		var->mlx.mlx_ptr, "./assets/wall4.xpm", &(x_y[0]), &(x_y[1]))))
		exit(0);
	ft_set_x_y(x_y, 960, 600);
	if (!(var->black_screen = mlx_xpm_file_to_image(var->mlx.mlx_ptr,
			"./assets/black_screen.xpm", &(x_y[0]), &(x_y[1]))))
		exit(0);
	ft_load_tex_addr(var);
}

void	ft_load_xpm(t_var *var, t_textures *s)
{
	int x_y[4];

	ft_set_x_y(x_y, 960, 600);
	ft_set_x_y(x_y + 2, 179, 50);
	if (!(s->menu = mlx_xpm_file_to_image(var->mlx.mlx_ptr,
		"./assets/menu.xpm", &(x_y[2]), &(x_y[3]))))
		exit(0);
	if (!(s->menu_blanc = mlx_xpm_file_to_image(var->mlx.mlx_ptr,
		"./assets/menu_blanc.xpm", &(x_y[2]), &(x_y[3]))))
		exit(0);
	if (!(s->main_menu = mlx_xpm_file_to_image(var->mlx.mlx_ptr,
		"./assets/main_menu.xpm", &(x_y[0]), &(x_y[1]))))
		exit(0);
	if (!(s->jouer = mlx_xpm_file_to_image(var->mlx.mlx_ptr,
		"./assets/jouer.xpm", &(x_y[1]), &(x_y[3]))))
		exit(0);
	if (!(s->jouer_blanc = mlx_xpm_file_to_image(var->mlx.mlx_ptr,
		"./assets/jouer_blanc.xpm", &(x_y[1]), &(x_y[3]))))
		exit(0);
	if (!(s->quitter = mlx_xpm_file_to_image(var->mlx.mlx_ptr,
		"./assets/quitter.xpm", &(x_y[1]), &(x_y[3]))))
		exit(0);
	if (!(s->quitter_blanc = mlx_xpm_file_to_image(var->mlx.mlx_ptr,
		"./assets/quitter_blanc.xpm", &(x_y[1]), &(x_y[3]))))
		exit(0);
}
