/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ravernhe <ravernhe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 17:56:12 by ravernhe          #+#    #+#             */
/*   Updated: 2019/11/30 17:33:39 by ravernhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	ft_error(int i)
{
	if (i == 1)
		ft_putstr("error: one of the map file's character is wrong");
	else if (i == 2)
		ft_putstr("error: a malloc failed");
	else if (i == 3)
		ft_putstr("error: spawn number is wrong. You must have ONE spawn");
	else if (i == 4)
		ft_putstr("error: empty file");
	else if (i == 5)
		ft_putstr("error: file not found");
	else if (i == 6)
		ft_putstr("error: spawn is in the wall");
	else
		ft_putstr("error");
	exit(0);
}
