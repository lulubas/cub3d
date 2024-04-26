/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:41:40 by damendez          #+#    #+#             */
/*   Updated: 2024/04/26 14:28:48 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * 1. Read file until first map line is found (considering textures and colors are found correctly before)
 * 2. Keep reading lines from the map, first line must be all 1s and next line must be same length
 * 3. For each line inside the map, check that it has only valid chars and keeps the map closed off with walls
 * 4. The last map line must be all 1s and the next line must not be a map line
 * 
 * doubts:	How do we handle if the map changes in size after the first line?
 *			...?
*/
static void	check_map(t_data *data, int fd)
{

}

/*
 * 1. Keep getting_next_line from fd until we found 6 lines that are textures/colors
 * 2. If line is valid and not a mapline, check if its a correct texture/color and increment line num counter
*/
static void	check_textures_and_colors(t_data *data, int fd)
{
	char	*line;
	int		i;

	line = get_next_line(fd);
	i = 0;
	while (line && i < 6)
	{
		if (*line != '\n' && line && !is_map_line(line))
			is_texorcolor(data, line, &i);
		if (line && *line != '\n' && is_map_line(line) && i < 6)
			ft_error(data, "Could not find 4 textures and 2 colors before the map", 1);
		free(line);
		if (i < 6)
			line = get_next_line(fd);
	}
	if (i != 6)
		ft_error(data, "Could not find 4 textures \
		and 2 colors before the map", 1);
}

static int	check_file_type(char *str)
{
	if (ft_strlen(str) < 5)
		return (1);
	else if (ft_strncmp(".cub", str + ft_strlen(str) - 4, 4))
		return (1);
	return (0);
}

/*
 * 1. Check number of input arguments 
 * 2. Check if input argument file type is valid (.cub)
 * 3. Open file checking for error
 * 4. Find/check for textures and colors from scene file
 * 5. Find map in scene file and check if its invalid			-> TO-DO
*/
void	check_scene(int argc, char **argv, t_data *data)
{
	int	fd;

	if (argc != 2)
		ft_error(data, "Invalid number of arguments", 1);
	if (check_file_type(argv[1]))
		ft_error(data, "Map file extension must be '.cub'", 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error(data, "Map file could not be opened", 1);
	check_textures_and_colors(data, fd);
	check_map(data, fd); // TO_DO
	//Adding filepath to the struct for the parser and closing the fd
	data->filepath = ft_strdup(argv[1]);
	close(fd);
}
