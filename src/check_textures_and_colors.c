/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_and_colors.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:04:28 by damendez          #+#    #+#             */
/*   Updated: 2024/05/24 01:17:49 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_color_values(t_data *data, char *line)
{
	char	**split;
	int		r;
	int		g;
	int		b;

	split = ft_split(line + 2, ',');
	if (!split)
		ft_error(data, "Malloc error", 1);
	if (ft_ptrlen(split) != 3)
		ft_error(data, "Color syntax error in map file", 1);
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if ((r >= 0 && r <= 255) && (g >= 0 && g <= 255) \
	&& (b >= 0 && b <= 255))
	{
		printf("Color is valid\n");
		free_split(split);
		return (0);
	}
	free_split(split);
	return (1);
}

void	check_ifloor_color(t_data *data, char *line)
{
	if (line[0] == 'F' || line[0] == 'C')
	{
		if (check_color_values(data, line))
			ft_error(data, "Invalid value used for color", 1);
	}
	else
		ft_error(data, "Invalid identifier used for color", 1);
}

void	check_if_tex(t_data *data, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		ft_error(data, "Malloc error", 1);
	if (ft_ptrlen(split) != 2)
		ft_error(data, "Texture syntax error in map file", 1);
	if (line[0] == 'N' && line[1] == 'O')
		printf("North texture identifier found\n");
	else if (line[0] == 'S' && line[1] == 'O')
		printf("South texture identifier found\n");
	else if (line[0] == 'E' && line[1] == 'A')
		printf("East texture identifier found\n");
	else if (line[0] == 'W' && line[1] == 'E')
		printf("West texture identifier found\n");
	else
		ft_error(data, "Invalid identifier used for texture", 1);
	free_split(split);
}

void	is_texorcolor(t_data *data, char *line, int *i)
{
	if (ft_strlen_n(line) == 2)
	{
		check_if_tex(data, line);
		++*i;
		printf("tex counter: i = %i\n", *i);
	}
	if (ft_strlen_n(line) == 1)
	{
		check_ifloor_color(data, line);
		++*i;
		printf("color counter: i = %i\n", *i);
	}
}
