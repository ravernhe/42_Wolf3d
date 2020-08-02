/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <glecler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:28:06 by glecler           #+#    #+#             */
/*   Updated: 2019/11/30 17:34:37 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	ft_error(int error_code)
{
	if (error_code == 1)
		ft_putstr("error: wrong character in map file\n");
	else if (error_code == 2)
		ft_putstr("error: malloc failed\n");
	else if (error_code == 3)
		ft_putstr("error: bad spawn #\n");
	else if (error_code == 4)
		ft_putstr("error: empty file\n");
	else if (error_code == 5)
		ft_putstr("error: file not found\n");
	else if (error_code == 6)
		ft_putstr("error: bad spawn\n");
	else if (error_code == 7)
		ft_putstr("error : map is not valid\n");
	else
		ft_putstr("error\n");
	exit(0);
}
