/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_textures_buttons.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamisdra <mamisdra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 18:15:58 by mamisdra          #+#    #+#             */
/*   Updated: 2019/11/28 20:45:48 by mamisdra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

static int	open_img_opt_button_num(t_var *var, int i)
{
	char	str[2];
	char	*s;
	char	*s1;

	while (i < 37)
	{
		str[0] = '0' + i - 27;
		str[1] = 0;
		if (!(s1 = ft_strjoin("./assets/op/", str)))
			exit(0);
		if (!(s = ft_strjoin(s1, ".bmp")))
			exit(0);
		if (!(var->key_texture[i] = SDL_LoadBMP(s)))
			exit(0);
		free(s);
		free(s1);
		i++;
	}
	return (i);
}

static void	open_img_opt_button_arrow(t_var *var, int i)
{
	char	str[2];
	char	*s;
	char	*s1;

	while (i < 41)
	{
		str[0] = '0' + i - 36;
		str[1] = 0;
		if (!(s1 = ft_strjoin("./assets/op/f", str)))
			exit(0);
		if (!(s = ft_strjoin(s1, ".bmp")))
			exit(0);
		if (!(var->key_texture[i] = SDL_LoadBMP(s)))
			exit(0);
		free(s);
		free(s1);
		i++;
	}
}

void		open_img_opt_button(t_var *var)
{
	int		i;
	char	str[2];
	char	*s;
	char	*s1;

	i = 0;
	while (i < 26)
	{
		str[0] = 'a' + i;
		str[1] = 0;
		if (!(s1 = ft_strjoin("./assets/op/", str)))
			exit(0);
		if (!(s = ft_strjoin(s1, ".bmp")))
			exit(0);
		if (!(var->key_texture[i] = SDL_LoadBMP(s)))
			exit(0);
		i++;
		free(s);
		free(s1);
	}
	if (!(var->key_texture[i] = SDL_LoadBMP("./assets/op/unknown.bmp")))
		exit(0);
	i = open_img_opt_button_num(var, i + 1);
	open_img_opt_button_arrow(var, i);
}
