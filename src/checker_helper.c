/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:04:28 by damendez          #+#    #+#             */
/*   Updated: 2024/04/19 16:29:17 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void check_if_tex(t_data *data, char *line)
{
	char **split;

	split = ft_split(line, ' ');
	if (!split)
		free_and_exit(data, "Malloc error", 1);
	if (ft_ptrlen(split) != 2)
		free_and_exit(data, "Texture syntax error in map file", 1);
	if (line[0] == 'N' && line[1] == 'O')
		// here we could save int struct map.notex variable
}