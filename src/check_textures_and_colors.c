/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_and_colors.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:04:28 by damendez          #+#    #+#             */
/*   Updated: 2024/05/29 14:35:42 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	all_nums_doub(char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (split[i][j] != '\0' && split[i][j] != '\n')
		{
			if (!is_num_or_space(split[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_color_values(t_data *data, char *line)
{
	char	**split;
	int		r;
	int		g;
	int		b;

	split = ft_split(line + 2, ',');
	if (!split)
		ft_error(data, "Malloc error", 1);
	if (ft_ptrlen(split) != 3 || !all_nums_doub(split))
		ft_error(data, "Color syntax error in map file", 1);
	r = ft_atoi(split[0]);
	g = ft_atoi(split[1]);
	b = ft_atoi(split[2]);
	if ((r >= 0 && r <= 255) && (g >= 0 && g <= 255) \
	&& (b >= 0 && b <= 255))
	{
		free_split(split);
		return (0);
	}
	free_split(split);
	return (1);
}

void	check_color(t_data *data, char *line)
{
	if (line[0] == 'F' || line[0] == 'C')
	{
		if (check_color_values(data, line))
			ft_error(data, "Invalid value used for color", 1);
	}
	else
		ft_error(data, "Invalid configuraton found in file", 1);
}

void	check_if_tex(t_data *data, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!split)
		ft_error(data, "Malloc error", 1);
	if (ft_ptrlen(split) != 2)
		ft_error(data, "Texture syntax error in map file", 1);
	ft_check_tex(data, split[1]);
	if (line[0] != 'N' && line[1] != 'O' && \
		line[0] != 'S' && line[1] != 'O' && \
		line[0] != 'E' && line[1] != 'A' && \
		line[0] != 'W' && line[1] != 'E')
	{
		free_split(split);
		ft_error(data, "Invalid configuraton found in file", 1);
	}
	free_split(split);
}

void	is_texorcolor(t_data *data, char *line, int *i)
{
	skip_spaces(line);
	if (ft_strlen_n(line) == 2)
	{
		check_if_tex(data, line);
		++*i;
	}
	else if (ft_strlen_n(line) == 1)
	{
		check_color(data, line);
		++*i;
	}
	else
		ft_error(data, "Invalid configuraton found in file", 1);
}
