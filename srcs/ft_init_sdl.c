/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sdl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamisdra <mamisdra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:03:21 by mamisdra          #+#    #+#             */
/*   Updated: 2019/11/30 16:55:56 by mamisdra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	ft_init_sdl(t_var *var)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
	{
		ft_putstr("SDL_Init error\n");
		exit(0);
	}
	if (!(var->sdl.window = SDL_CreateWindow("WOLFCRAFT",
	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SIZE_X, SIZE_Y, 0)))
	{
		ft_putstr("SDL_CreateWindow error\n");
		exit(0);
	}
	if (!(var->sdl.render = SDL_CreateRenderer(var->sdl.window, -1, 1)))
	{
		ft_putstr("SDL_CreateRenderer error\n");
		exit(0);
	}
}
