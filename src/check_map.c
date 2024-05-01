/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:27:58 by damendez          #+#    #+#             */
/*   Updated: 2024/05/01 15:00:57 by damendez         ###   ########.fr       */
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
/*
 * 1. First and last line must all be 1s (or spaces)
 * 2. Every line needs to start and end with 1
*/
void	check_closed(t_data *data)
{
	int	y;
	t_list *tmp;

	y = 0;
	tmp = data->lst;
	while (tmp != NULL)
	{
		printf("Map row being checked: %i\n", y);
		if (y == 0 || y == data->map_y)
		{
			if (!all_ones(tmp->str))
				ft_error(data, "Error: Map not closed 1, Invalid map", 1);
		}
		else if (tmp->str[0] != '1')
			ft_error(data, "Error: Map not closed 2, Invalid map", 1);
		else if (tmp->str[ft_strlen(tmp->str) - 1] != '1')
		{
			//printf("Map row n.%i last positon: %c\n", y, tmp->str[ft_strlen(tmp->str) - 1]);
			ft_error(data, "Error: Map not closed 3, Invalid map", 1);
		}
		y++;
		tmp = tmp->next;
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
	check_player_count(data);
	check_closed(data);
	check_playable(data);
}