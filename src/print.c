/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 02:39:50 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/07 18:41:20 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void print_2darray(char **darray)
{
    int i;

    i = 0;
	if (!darray)
	{
		printf("NULL array\n");
		return ;
	}
    while(darray[i])
    {
        printf("[%d]:%s ", i, darray[i]);
        i++;
    }
	printf("\n");
}

char	*tile_to_string(t_tile tile)
{
	if (tile == SPACE)
		return ("V");
	else if (tile == WALL)
		return ("1");
	else if (tile == EMPTY)
		return ("0");
	else if (tile == NORTH)
		return ("N");
	else if (tile == SOUTH)
		return ("S");
	else if (tile == EAST)
		return ("E");
	else if (tile == WEST)
		return ("W");
	else
		return ("ERR");
}

void	print_map(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < data->map_y)
	{
		while (x < data->map_x)
			printf("%s ", tile_to_string(data->map[y][x++]));
		printf("\n");
		x = 0;
		y++;
	}
}

void    print_data(t_data *data)
{
    printf("===Data content===\n");
    printf("filepath=%s\n", data->filepath);
    printf("no_texture=%s\n", data->no_texture);
    printf("so_texture=%s\n", data->so_texture);
    printf("ea_texture=%s\n", data->ea_texture);
    printf("we_texture=%s\n", data->we_texture);
	printf("F_color=");
	print_2darray(data->F_color);
	printf("C_color=");
	print_2darray(data->C_color);
	printf("player_x=%d\n", data->player_x);
	printf("player_y=%d\n", data->player_y);
	printf("mapX=%d\n", data->mapX);
	printf("mapY=%d\n", data->mapY);
	printf("playerPosX=%f\n", data->playerPosX);
	printf("playerPosY=%f\n", data->playerPosY);
	printf("playerDirX=%f\n", data->playerDirX);
	printf("playerDirY=%f\n", data->playerDirY);
	printf("planeX=%f\n", data->planeX);
	printf("planeY=%f\n", data->planeY);
	printf("sideDistX=%f\n", data->sideDistX);
	printf("sideDistY=%f\n", data->sideDistY);
	printf("deltaDistX=%f\n", data->deltaDistX);
	printf("deltaDistY=%f\n", data->deltaDistY);
	printf("stepX=%d\n", data->stepX);
	printf("stepY=%d\n", data->stepY);
	printf("-----MAP ARRAY------\n");
	print_map(data);
	printf("--------------------\n");
	printf("====================\n");
}
