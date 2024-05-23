/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 02:39:50 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/24 01:23:40 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_2darray(char **darray)
{
	int	i;

	i = 0;
	if (!darray)
	{
		printf("NULL array\n");
		return ;
	}
	while (darray[i])
	{
		printf("[%d]:%s ", i, darray[i]);
		i++;
	}
	printf("\n");
}

char	*tile_to_string(t_tile tile)
{
	if (tile == SPACE)
		return ("SPA");
	else if (tile == WALL)
		return ("WAL");
	else if (tile == EMPTY)
		return ("EMP");
	else if (tile == P_NORTH)
		return ("NOR");
	else if (tile == P_SOUTH)
		return ("SOU");
	else if (tile == P_EAST)
		return ("EAS");
	else if (tile == P_WEST)
		return ("WES");
	else
		return ("ERR");
}

void	print_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < data->map_size_y)
	{
		while (x < data->map_size_x)
			printf("%s ", tile_to_string(data->map[y][x++]));
		printf("\n");
		x = 0;
		y++;
	}
}

void	print_data(t_data *data)
{
	printf("===Data content===\n");
	printf("filepath=%s\n", data->filepath);
	printf("floor_color=%d\n", data->floor_color);
	printf("ceiling_color=%d\n", data->ceiling_color);
	printf("player_x=%d\n", data->player_x);
	printf("player_y=%d\n", data->player_y);
	printf("-----MAP ARRAY------\n");
	print_map(data);
	printf("--------------------\n");
	printf("====================\n");
}

void	print_scene(t_scene *scene)
{
	printf("player_posx=%f\n", scene->player_posx);
	printf("player_posy=%f\n", scene->player_posy);
	printf("player_dirx=%f\n", scene->player_dirx);
	printf("player_diry=%f\n", scene->player_diry);
	printf("ray_dirx=%f\n", scene->ray_dirx);
	printf("ray_diry=%f\n", scene->ray_diry);
	printf("plane_x=%f\n", scene->plane_x);
	printf("plane_y=%f\n", scene->plane_y);
	printf("side_distx=%f\n", scene->side_distx);
	printf("side_disty=%f\n", scene->side_disty);
	printf("delta_distx=%f\n", scene->delta_distx);
	printf("delta_disty=%f\n", scene->delta_disty);
	printf("map_x=%d\n", scene->map_x);
	printf("map_y=%d\n", scene->map_y);
	printf("step_x=%d\n", scene->step_x);
	printf("step_y=%d\n", scene->step_y);
	printf("perp_walldist=%f\n", scene->perp_walldist);
}
