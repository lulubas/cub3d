/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:41:40 by damendez          #+#    #+#             */
/*   Updated: 2024/04/19 16:29:17 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	is_texorcolor(char *line, int *i)
{
	if (ft_strlen_n(line) == 2)
	{
		check_if_tex(line);
		++*i;
	}
	if (ft_strlen_n(line) == 1)
	{
		check_if_color(line);
		++*i;
	}
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
			is_texorcolor(line, &i);
		free(line);
		if (i < 6)
		line = get_next_line(fd);
	}
	if (i != 6)
		free_and_exit(data, "Could not find 4 textures and 2 colors before the map", 1);
}

static int	check_file_type(char *str)
{
	if (ft_strlen(str) < 5)
		return (1);
	else if (ft_strncmp(".cub", str + ft_strlen(str) - 4, 4))
		return (1);
	return (0);
}

// static void	check_map(t_data *data, int fd)
// {

// }

/*
!!I think if better if the checker function sticks to checking if map
 * 1. Check number of input arguments 
 * 2. Check if input argument file type is valid (.cub) 						-> TO-DO
 * 3. Open file checking for error
 * 4. Find/check for textures and colors from scene file						-> TO-DO
 * 5. Find map in scene file and save to struct (rows, columns, map itself)		-> TO-DO
 * 6. Check if parsed map is valid (invalid player count, ...)		 			-> TO-DO 
 * 
 * !!SUGGESTION!!: I think in the checker we should just check that the scene is  correct 
 * (textures/map files, walls, playercount etc.) and fill up the struct only in the parser.
 *  The only thing to fill up here would be the filepath (argv[1]) as it is needed for the parser.
*/
void	check_scene(int argc, char **argv, t_data *data)
{
	int	fd;

	if (argc != 2)
		free_and_exit(data, "Invalid number of arguments", 1);
	if (check_file_type(argv[1]))
		free_and_exit(data, "Map file extension must be '.cub'", 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		free_and_exit(data, "Map file could not be opened", 1);
	check_textures_and_colors(data, fd); // TO-DO
	//check_map(/*data, */fd); // TO_DO
	
	//Adding filepath to the struct for the parser and closing the fd
	data->filepath = ft_strdup(argv[1]);
	close(fd);
}