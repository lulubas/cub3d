/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 13:41:40 by damendez          #+#    #+#             */
/*   Updated: 2024/04/17 17:47:00 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*
 * should exit with err
*/
static void	exit_error(/*char *str,*/ int err)
{
	exit(err);
}

/*
 * 1. Check number of input arguments
 * 2. Check if input argument scene file is valid (.cub)
 * 3. Open file checking for error
 * 4. Find/check for textures and colors from scene file
 * 5. Find map in scene file and save to struct (rows, columns, map itself)
 * 6. Check if parsed map is valid (invalid player count, ...)
 * 7. ...
*/
void	check_scene(int argc, char **argv, t_data *data)
{
	int	fd;

	if (argc != 2)
		//exit_error("Invalid number of arguments\n");
	
}