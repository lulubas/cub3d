/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:41:40 by damendez          #+#    #+#             */
/*   Updated: 2024/04/18 21:58:11 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
 * 1. Check if string length is valid ( > .cub'\0')
 * 2. Check that the last for chars are ".cub"
*/
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

// static void	check_textures_and_colors(t_data *data, int fd)
// {

// }


/*
!!I think if better if the checker function sticks to checking if map
 * 1. Check number of input arguments 
 * 2. Check if input argument file type is valid (.cub) 						-> TO-DO
 * 3. Open file checking for error
 * 4. Find/check for textures and colors from scene file						-> TO-DO
 * 5. Find map in scene file and save to struct (rows, columns, map itself)		-> TO-DO
 * 6. Check if parsed map is valid (invalid player count, ...)					-> TO-DO 
 * 7. ...
 * 
 * !!SUGGESTION!!: I think in the checker we should just check that the scene is  correct 
 * (textures/map files, walls, playercount etc.) and fill up the struct only in the parser.
 *  The only thing to fill up here would be the filepath (argv[1]) as it is needed for the parser.
 * 
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
	//check_textures_and_colors(/*data, */fd); // TO-DO
	//check_map(/*data, */fd); // TO_DO
	
	//Adding filepath to the struct for the parser and closing the fd
	data->filepath = ft_strdup(argv[1]);
	close(fd);
}