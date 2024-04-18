/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:46:38 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/18 14:22:25 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdlib.h>	// malloc, free, exit
#include <unistd.h>	// close, read, write
#include <stdio.h>	// printf, perror
#include <string.h>	// strerror
#include <fcntl.h>	// open
#include <math.h>
#include "../lib/libft/libft.h"
#include "../lib/mlx/mlx.h"

typedef struct s_data
{
	/* data */
}		t_data;

t_data	*init_main_struct(void);
void	check_scene(int argc, char **argv, t_data *data);
void	parse_map(t_data *data);
void	init_game(t_data *data);
void	free_all(t_data *data);
#define CUB3D_H

#include "lib.h"
#include "libft.h"
#include "struct.h"
#include "fct.h"

#endif