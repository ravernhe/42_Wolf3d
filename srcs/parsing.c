/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glecler <glecler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 17:28:06 by glecler           #+#    #+#             */
/*   Updated: 2019/11/30 17:34:00 by glecler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf.h"

void	ft_init_var(t_var *var)
{
	var->x_max = 0;
	var->y_max = 0;
	var->map = NULL;
}

int		ft_check_char(char *buff)
{
	int i;

	i = 0;
	if (!(buff[i]))
		return (1);
	while (buff[i])
	{
		if (buff[i] == '1' || buff[i] == '0' || buff[i] == ' ' ||\
			buff[i] == '\n' || buff[i] == '7')
			i++;
		else
			return (1);
	}
	return (0);
}

void	ft_parsing_map(int fd, t_var *var)
{
	char	*buff;
	char	*str;
	int		ret;
	int		token;
	size_t	nb_char;

	token = 0;
	ft_init_var(var);
	if (!(str = ft_strnew(0)))
		ft_error(2);
	while ((ret = get_next_line(fd, &buff)))
	{
		if (token == 0 && (token = 1))
			nb_char = ft_strlen(buff);
		if (nb_char != ft_strlen(buff))
			ft_error(1);
		if (ft_check_char(buff) == 1)
			ft_error(1);
		if (!(str = ft_strjoin_free_s1s2_newline(str, buff)))
			ft_error(2);
		var->y_max += 1;
	}
	ft_check_map(var, ret, nb_char, str);
}
