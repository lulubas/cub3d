/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:25:43 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/24 18:09:02 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_tile(char c, t_tile *tile, t_data *data)
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
	else
		ft_error(data, "Wrong Character in map", 1);
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

void	get_map_bounds(t_data *data)
{
	t_list	*tmp;
	size_t	max_x;
	int		y;

	max_x = 0;
	y = 0;
	tmp = data->lst;
	while (tmp)
	{
		if (ft_strlen(tmp->str) > max_x)
			max_x = ft_strlen(tmp->str);
		y++;
		tmp = tmp->next;
	}
	data->map_size_x = (int)max_x + 2;
	data->map_size_y = y + 2;
}

t_tile	**init_map(t_data *data)
{
	t_tile	**new_map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	get_map_bounds(data);
	new_map = (t_tile **)malloc(sizeof(t_tile *) * data->map_size_y);
	if (!new_map)
		ft_error(data, "Failed to allocate map", 1);
	while (i < data->map_size_y)
	{
		new_map[i] = (t_tile *)malloc(sizeof(t_tile) * data->map_size_x);
		if (!new_map[i])
			ft_error(data, "Failed to allocate map tiles", 1);
		while (j < data->map_size_x)
			new_map[i][j++] = SPACE;
		j = 0;
		i++;
	}
	return (new_map);
}

t_tile	**parse_list_to_array(t_list *lst, t_data *data)
{
	t_tile	**map;
	t_list	*tmp;
	int		x;
	int		y;

	map = init_map(data);
	tmp = lst;
	x = 1;
	y = 1;
	while (tmp)
	{
		while (tmp->str[x - 1])
		{
			parse_tile(tmp->str[x - 1], &map[y][x], data);
			parse_player(x, y, map, data);
			x++;
		}
		x = 1;
		y++;
		tmp = tmp->next;
	}
	return (map);
}
