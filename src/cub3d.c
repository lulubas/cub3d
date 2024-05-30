/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:45:20 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/30 16:32:38 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	(void)argv;
	(void)argc;
	data = init_data_struct();
	if (!data)
		return (1);
	check_scene(argc, argv, data);
	parse_scene(data);
	check_map(data);
	init_mlx(data);
	mlx_loop_hook(data->mlx, raycast_and_render, data);
	mlx_loop(data->mlx);
	free_all(data);
	exit(0);
}
