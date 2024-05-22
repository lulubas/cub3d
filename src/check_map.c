/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:27:58 by damendez          #+#    #+#             */
/*   Updated: 2024/05/22 16:24:37 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	 check_player_count(t_data *data)
{
	int	x;
	int	flag;
	t_list *tmp;

	flag = 0;
	tmp = data->lst;
	while (tmp != NULL)
	{
		x = 0;
		while (tmp->str[x] != '\0')
		{
			if (is_player(tmp->str[x++]))
			{
				flag++;
				if (flag > 1)
					ft_error(data, "Error: Too many players in map", 1);
			}
		}
		tmp = tmp->next;
	}
	if (flag == 0)
		ft_error(data, "Error: Player needed in map", 1);
}

void	check_closed(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map_y)
	{
		x = 0;
		while (x < data->map_x)
		{
			if (data->map[y][x] == SPACE)
			{
				// printf("checking is surrounded by space or wall: map[%i][%i]\n", y, x);
				if (!is_surrounded_space_or_wall(data, y, x))
					ft_error(data, "Error: Map is not closed, Invalid map", 1);
			}
			x++;
		}
		y++;
	}
}

void	check_playable(t_data *data)
{
	int	x;
	int	y;
	int	flag;

	y = 0;
	flag = 0;
	while (y < data->map_y)
	{
		x = 0;
		while (x < data->map_x)
		{
			if (data->map[y][x] == EMPTY)
				flag++;
			x++;
		}
		y++;
	}
	if (flag < 1)
		ft_error(data, "Error: Map not playable, Invalid map", 1);
}

void	check_map(t_data *data)
{
	check_closed(data);
	check_player_count(data);
	check_playable(data);
}