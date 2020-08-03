/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravernhe <ravernhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:28:06 by ravernhe          #+#    #+#             */
/*   Updated: 2019/12/02 14:50:19 by mamisdra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

int		**fill_map_struct(t_var var)
{
	int		**map;
	int		x_x2_y[3];

	x_x2_y[2] = -1;
	if (!(map = malloc(sizeof(int *) * var.y_max)))
		ft_error(2);
	while (++x_x2_y[2] != var.y_max)
	{
		if (!(map[x_x2_y[2]] = malloc(sizeof(int) * (var.x_max))))
			ft_error(2);
	}
	x_x2_y[2] = 0;
	while (x_x2_y[2] != var.y_max)
	{
		x_x2_y[0] = 0;
		x_x2_y[1] = 0;
		while (x_x2_y[0] <= ((var.x_max) * 2))
		{
			map[x_x2_y[2]][x_x2_y[1]] = var.map[x_x2_y[2]][x_x2_y[0]] - 48;
			x_x2_y[1] += 1;
			x_x2_y[0] += 2;
		}
		x_x2_y[2]++;
	}
	return (map);
}

void	player_data_set(t_player *player, t_var *var)
{
	int x;
	int y;

	y = 0;
	while (y != var->y_max)
	{
		x = 0;
		while (x != var->x_max)
		{
			if (var->m[y][x] == 7)
			{
				var->spawn.x = BLOCK_SIZE * x + BLOCK_SIZE / 2;
				var->spawn.y = BLOCK_SIZE * y + BLOCK_SIZE / 2;
				player->pos.x = var->spawn.x;
				player->pos.y = var->spawn.y;
			}
			x++;
		}
		y++;
	}
	player->height = BLOCK_SIZE / 2;
	player->fov = 60;
	player->angle = 210;
}

void	init_key_move(t_var *var)
{
	var->key.left = SDLK_a;
	var->key.right = SDLK_d;
	var->key.forw = SDLK_w;
	var->key.back = SDLK_s;
	var->select_key = 0;
	var->key_id[0] = 3;
	var->key_id[1] = 0;
	var->key_id[2] = 22;
	var->key_id[3] = 18;
}

void	is_first_char_zero(char *str)
{
	int		fd;
	int		ret;
	char	buff[2];

	fd = open(str, O_RDONLY);
	ret = read(fd, buff, 2);
	buff[ret] = 0;
	close(fd);
	if (buff[0] == 0)
		ft_error(44);
}

int		main(int ac, char **av)
{
	int				fd;
	t_var			var;
	t_player		player;

	if (ac != 2 || (fd = open(av[1], O_RDONLY)) < 0)
	{
		ft_putstr("usage : ./wolf3d [map]\n");
		exit(0);
	}
	is_first_char_zero(av[1]);
	init_key_move(&var);
	parsing_map(fd, &var);
	var.m = fill_map_struct(var);
	player_data_set(&player, &var);
	ft_init_sdl(&var);
	open_wall_texture(&var);
	open_img_opt_button(&var);
	close(fd);
	display(&var, &player);
	return (0);
}
