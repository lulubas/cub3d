/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:27:58 by damendez          #+#    #+#             */
/*   Updated: 2024/04/29 16:34:51 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_map_line(char *line)
{
	while (*line != '\0')
	{
		if (*line != ' ' && *line != '0' && *line != '1' && \
		*line != 'N' && *line != 'S' && *line != 'E' && *line \
		!= 'E' && *line != '\n')
			return (0);
		++line;
	}
	return (1);
}

static int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

static int	all_ones(char *str)
{
	while (*str == '1')

		str++;
	if (*str == '\0')
		return (1);
	return (0);
}

void	check_player_count(t_data *data)
{
	int	x;
	int	flag;

	x = 0;
	flag = 0;
	while (data->lst != NULL)
	{
		x = 0;
		while (data->lst->str[x] != '\0')
		{
			if (is_player(data->lst->str[x++]))
			{
				flag++;
				if (flag > 1)
					ft_error(data, "Error: Too many players in map", 1);
			}
		}
		data->lst = data->lst->next;
	}
	if (flag == 0)
		ft_error(data, "Error: Player needed in map", 1);
}
/*
 * 1. First and last line must all be 1s (or spaces)
 * 2. Every line needs to start and end with 1
*/
void	check_closed(t_data *data)
{
	int	i;
	int	row;

	i = 0;
	row = 0;
	while (data->lst != NULL)
	{
		if (row == 0 || row == data->map_y)
		{
			if (!all_ones(data->lst->str))
				ft_error(data, "Error: Map not closed, Invalid map", 1);
		}
		else if (data->lst->str[0] != '1' || 
		data->lst->str[ft_strlen(data->lst->str - 1)] != '1')
		{
			ft_error(data, "Error: Map not closed, Invalid map", 1);
		}
		row++;
		data->lst = data->lst->next;
	}
}