/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:07:45 by damendez          #+#    #+#             */
/*   Updated: 2024/04/30 15:09:52 by damendez         ###   ########.fr       */
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

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	all_ones(char *str)
{
	while (*str == '1')

		str++;
	if (*str == '\0')
		return (1);
	return (0);
}