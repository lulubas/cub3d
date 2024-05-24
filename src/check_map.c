/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:27:58 by damendez          #+#    #+#             */
/*   Updated: 2024/05/24 18:24:50 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	check_player_count(t_data *data)
{
	int	x;
	int	y;
	int	player_count;

	x = 0;
	y = 0;
	player_count = 0;
	while (y < data->map_size_y)
	{
		x = 0;
		while (x < data->map_size_x)
		{
			if (data->map[y][x] == P_NORTH || data->map[y][x] == P_SOUTH \
				|| data->map[y][x] == P_EAST || data->map[y][x] == P_WEST)
				player_count++;
			x++;
		}
		y++;
	}
	if (player_count != 1)
		ft_error(data, "There needs to be 1 Player", 1);
}

void	check_closed(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->map_size_y)
	{
		x = 0;
		while (x < data->map_size_x)
		{
			if (data->map[y][x] == SPACE)
			{
				if (!is_surrounded_space_or_wall(data, y, x))
					ft_error(data, "Error: Map is not closed", 1);
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
	while (y < data->map_size_y)
	{
		x = 0;
		while (x < data->map_size_x)
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
