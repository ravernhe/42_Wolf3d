/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <glecler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:28:06 by glecler           #+#    #+#             */
/*   Updated: 2019/12/02 14:50:19 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	ft_init_key(t_key *key)
{
	key->forw = 0;
	key->back = 0;
	key->right = 0;
	key->left = 0;
}

int		**ft_fill_map_struct(t_var var)
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

void	ft_player_data_set(t_player *player, t_var *var)
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
				var->spawn.x = BSD * x + BSD / 2;
				var->spawn.y = BSD * y + BSD / 2;
				player->pos.x = var->spawn.x;
				player->pos.y = var->spawn.y;
			}
			x++;
		}
		y++;
	}
	player->height = BSD / 2;
	player->angle = 180;
}

void	ft_is_first_char_zero(char *str)
{
	int		fd;
	int		ret;
	char	buff[2];

	fd = open(str, O_RDONLY);
	ret = read(fd, buff, 2);
	buff[ret] = 0;
	close(fd);
	if (buff[0] == 0)
		ft_error(7);
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
	ft_init_key(&(var.key));
	ft_is_first_char_zero(av[1]);
	ft_parsing_map(fd, &var);
	var.m = ft_fill_map_struct(var);
	ft_player_data_set(&player, &var);
	ft_init_mlx(&var);
	ft_load_texture(&var);
	close(fd);
	ft_display(&var, &player);
	return (0);
}
