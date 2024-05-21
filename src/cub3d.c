/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:45:20 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/21 17:12:47 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_data	*data;

	data = init_data_struct();
	if (!data)
		return (1);
	(void)argv;
	(void)argc;
	//check_scene(argc, argv, data);
	//parse_scene(data);
	//init_mlx(data);
	//mlx_loop_hook(data->mlx, raycast_and_render, data);
	//mlx_loop(data->mlx);
	//Use function below to print the content of data struct
	//print_data(data);
	free_all(data);
	return (0);
}