/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <glecler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:25:03 by glecler           #+#    #+#             */
/*   Updated: 2019/11/28 16:18:01 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int				ft_put_pixel_img(t_var *var, int x, int y, unsigned char *rgb)
{
	char	*cpy;

	cpy = var->mlx.img_addr;
	if (rgb == 0)
		return (0);
	var->mlx.img_addr += y * var->mlx.s_l + x * 4;
	*(var->mlx.img_addr) = rgb[0];
	*(var->mlx.img_addr + 1) = rgb[1];
	*(var->mlx.img_addr + 2) = rgb[2];
	var->mlx.img_addr = cpy;
	return (1);
}

int				ft_get_rgb_from_img(t_mlx_img mlx_img, int x, int y,
	unsigned char *rgb)
{
	mlx_img.img_addr += y * BSI * 4 + x * 4;
	rgb[0] = *(mlx_img.img_addr);
	rgb[1] = *(mlx_img.img_addr + 1);
	rgb[2] = *(mlx_img.img_addr + 2);
	return (1);
}

t_dimensions	ft_mlx_img_dimensions(int x, int y, int w, int h)
{
	t_dimensions dim;

	dim.x = x;
	dim.y = y;
	dim.width = w;
	dim.height = h;
	return (dim);
}

void			ft_put_image(t_var *var, void *img_ptr, t_dimensions dim)
{
	t_mlx_img	mlx_img;
	int			h;
	int			w;

	h = 0;
	w = 0;
	mlx_img.img_ptr = img_ptr;
	if (!(mlx_img.img_addr = mlx_get_data_addr(mlx_img.img_ptr,
		&(mlx_img.bpp), &(mlx_img.s_l), &(mlx_img.endian))))
		exit(0);
	while (h < dim.height)
	{
		w = 0;
		while (w < dim.width && (h + dim.y < SIZE_Y) && (w + dim.x < SIZE_X))
		{
			(var->mlx.img_addr)[(h + dim.y) * var->mlx.s_l + (w + dim.x)
				* 4] = (mlx_img.img_addr)[h * mlx_img.s_l + w * 4];
			(var->mlx.img_addr)[(h + dim.y) * var->mlx.s_l + (w + dim.x)
				* 4 + 1] = (mlx_img.img_addr)[h * mlx_img.s_l + w * 4 + 1];
			(var->mlx.img_addr)[(h + dim.y) * var->mlx.s_l + (w + dim.x)
				* 4 + 2] = (mlx_img.img_addr)[h * mlx_img.s_l + w * 4 + 2];
			w++;
		}
		h++;
	}
}
