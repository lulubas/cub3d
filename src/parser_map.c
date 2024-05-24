/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:25:43 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/24 14:51:06 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_tile(char c, t_tile *tile)
{
	if (c == ' ')
		*tile = SPACE;
	else if (c == '1')
		*tile = WALL;
	else if (c == '0')
		*tile = EMPTY;
	else if (c == 'N')
		*tile = P_NORTH;
	else if (c == 'S')
		*tile = P_SOUTH;
	else if (c == 'E')
		*tile = P_EAST;
	else if (c == 'W')
		*tile = P_WEST;
}

void	parse_player(int x, int y, t_tile **map, t_data *data)
{
	if (map[y][x] == P_NORTH || map[y][x] == P_SOUTH || \
		map[y][x] == P_EAST || map[y][x] == P_WEST)
	{
		data->player_x = x;
		data->player_y = y;
		data->scene->player_posx = x + 0.5;
		data->scene->player_posy = y + 0.5;
	}
}

t_tile	**parse_list_to_array(t_list *lst, t_data *data)
{
	t_tile	**map;
	t_list	*tmp;
	int		x;
	int		y;

	map = init_map(lst, data);
	tmp = lst;
	x = 1;
	y = 1;
	while (tmp)
	{
		while (tmp->str[x - 1])
		{
			parse_tile(tmp->str[x - 1], &map[y][x]);
			parse_player(x, y, map, data);
			x++;
		}
		x = 1;
		y++;
		tmp = tmp->next;
	}
	return (map);
}
