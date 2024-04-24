/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_and_colors.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:04:28 by damendez          #+#    #+#             */
/*   Updated: 2024/04/24 13:50:30 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void check_if_tex(t_data *data, char *line)
{
	char **split;

	split = ft_split(line, ' ');
	if (!split)
		ft_error(data, "Malloc error", 1);
	if (ft_ptrlen(split) != 2)
		ft_error(data, "Texture syntax error in map file", 1);

	// here we could save map.tex variables
	if (line[0] == 'N' && line[1] == 'O')
		printf("North texture identifier found\n");
	else if (line[0] == 'S' && line[1] == 'O')
		printf("South texture identifier found\n");	
	if (line[0] == 'E' && line[1] == 'A')
		printf("East texture identifier found\n");	
	if (line[0] == 'W' && line[1] == 'E')
		printf("West texture identifier found\n");	
	else
		ft_error(data, "Invalid identifier used for texture", 1);
	free_split(split);
}

void check_if_color(t_data *data, char *line)
{
	char **split;

	split = ft_split(line, ',');
	if (!split)
		ft_error(data, "Malloc error", 1);
	if (ft_ptrlen(split) != 4)
		ft_error(data, "Color syntax error in map filer", 1);
	if (line[0] == 'C')
	{
		printf("Celing color identifier found\n");
		int	ceiling_r;
		int	ceiling_g;
		int	ceiling_b;

		ceiling_r = ft_atoi(&line[1]);
		ceiling_g = ft_atoi(&line[2]);
		ceiling_b = ft_atoi(&line[3]);

		if ((ceiling_r >= 0 && ceiling_r <= 255) && (ceiling_g >= 0 && ceiling_g <= 255) 
		&& (ceiling_b >= 0 && ceiling_b <= 255))
			printf("Ceiling color is valid\n");
		else
			ft_error(data, "Valid identifier but invalid color for Celing", 1);
	}	
	else if (line[0] == 'F')
	{
		printf("Floor color identifier found\n");
		int	floor_r;
		int	floor_g;
		int	floor_b;

		floor_r = ft_atoi(&line[1]);
		floor_g = ft_atoi(&line[2]);
		floor_b = ft_atoi(&line[3]);

		if ((floor_r >= 0 && floor_r <= 255) && (floor_g >= 0 && floor_g <= 255) 
		&& (floor_b >= 0 && floor_b <= 255))
			printf("Floor color is valid\n");
		else
			ft_error(data, "Valid identifier but invalid color for Floor", 1);
	}
	else
		ft_error(data, "Invalid color identifier\n", 1);
	free_split(split);
}