/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <glecler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:28:06 by glecler           #+#    #+#             */
/*   Updated: 2019/11/30 17:34:29 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	ft_put_wall_around_the_map(int hei, int len, t_var *var)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (var->map[0][x])
	{
		if (var->map[0][x] == '7' || var->map[hei - 1][x] == '7')
			ft_error(6);
		var->map[0][x] = '1';
		var->map[hei - 1][x] = '1';
		x++;
	}
	while (y < hei)
	{
		if (var->map[y][0] == '7' || var->map[y][len * 2] == '7')
			ft_error(6);
		var->map[y][0] = '1';
		var->map[y][len * 2] = '1';
		y++;
	}
}

int		ft_check_spawn(char *str)
{
	int i;
	int spawn;

	i = 0;
	spawn = 0;
	while (str[i])
	{
		if (str[i] == '7')
			spawn++;
		i++;
	}
	if (spawn > 1 || spawn == 0)
		return (1);
	return (0);
}

int		ft_check_space_between_digit(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (i % 2 != 0)
		{
			if (str[i] != ' ' && str[i] != '\n')
				return (1);
		}
		else
		{
			if (str[i] == ' ' || str[i] == '\n')
				return (1);
		}
		i++;
	}
	return (0);
}

void	ft_check_map(t_var *var, int ret, size_t nb_char, char *str)
{
	if (ret == -1 || var->y_max == 0)
		ft_error(-1);
	if (ft_check_spawn(str) == 1)
		ft_error(3);
	if (ft_check_space_between_digit(str) == 1)
		ft_error(1);
	var->x_max = (nb_char + 1) / 2;
	if (!(var->map = split(str, '\n')))
		ft_error(2);
	ft_put_wall_around_the_map(var->y_max, var->x_max, var);
	free(str);
}
