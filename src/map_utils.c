/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:07:45 by damendez          #+#    #+#             */
/*   Updated: 2024/05/06 19:15:41 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * map[y - 1][x - 1]	map[y - 1][x]	map[y - 1][x + 1]
 * map  [y]  [x - 1]	map  [y]  [x]	map  [y]  [x + 1]
 * map[y + 1][x - 1]	map[y + 1][x]	map[y + 1][x + 1]
*/
int	is_surrounded_space_or_wall(t_tile **map, int y, int x)
{
	int	tmpy;
	int	tmpx;

	tmpy = y - 1;
	tmpx = x - 1;
	while (tmpy <= y + 1)
	{
		tmpx = x - 1;
		while (tmpx <= x + 1)
		{
			if (map[tmpy][tmpx])
			{
				if (tmpx != x && tmpy != y)
				{
					if (map[tmpy][tmpx] != SPACE && map[tmpy][tmpx] != WALL) // TO-DO
						return (0);
				}
			}
			tmpx++;		
		}
		tmpy++;
	}
	return (1);
}

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

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	all_ones(char *str)
{
	int i;

	i = 0;
	while (str[i] == '1')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}