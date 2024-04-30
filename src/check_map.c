/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:27:58 by damendez          #+#    #+#             */
/*   Updated: 2024/04/30 17:34:21 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	 check_player_count(t_data *data)
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
// void	check_closed(t_data *data)
// {
// 	int	y;

// 	y = 0;
// 	while (y <= data->map_y)
// 	{
// 		if (y == 0 || y == data->map_y)
// 		{
// 			if (!all_walls(data->map[y], ))
// 				ft_error(data, "Error: Map not closed, Invalid map", 1);
// 		}
// 		else if (data->lst->str[0] != '1' || 
// 		data->lst->str[ft_strlen(data->lst->str - 1)] != '1')
// 		{
// 			ft_error(data, "Error: Map not closed, Invalid map", 1);
// 		}
// 		row++;
// 		data->lst = data->lst->next;
// 	}
// }

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
	check_player_count(data);
	//check_closed(data);
	check_playable(data);
}