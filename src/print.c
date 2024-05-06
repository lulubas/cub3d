/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 02:39:50 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/06 15:49:25 by lbastien         ###   ########.fr       */
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
		return ("SPA");
	else if (tile == WALL)
		return ("WAL");
	else if (tile == EMPTY)
		return ("EMP");
	else if (tile == NORTH)
		return ("NOR");
	else if (tile == SOUTH)
		return ("SOU");
	else if (tile == EAST)
		return ("EAS");
	else if (tile == WEST)
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
	printf("F_color=%d\n", data->F_color);
	printf("C_color=%d\n", data->C_color);
	printf("player_x=%d\n", data->player_x);
	printf("player_y=%d\n", data->player_y);
	printf("-----MAP ARRAY------\n");
	print_map(data);
	printf("--------------------\n");
	printf("====================\n");
}

void	print_scene(t_scene *scene)
{
	printf("playerPosX=%f\n", scene->playerPosX);
	printf("playerPosY=%f\n", scene->playerPosY);
	printf("playerDirX=%f\n", scene->playerDirX);
	printf("playerDirY=%f\n", scene->playerDirY);
	printf("rayDirX=%f\n", scene->rayDirX);
	printf("rayDirY=%f\n", scene->rayDirY);
	printf("planeX=%f\n", scene->planeX);
	printf("planeY=%f\n", scene->planeY);
	printf("sideDistX=%f\n", scene->sideDistX);
	printf("sideDistY=%f\n", scene->sideDistY);
	printf("deltaDistX=%f\n", scene->deltaDistX);
	printf("deltaDistY=%f\n", scene->deltaDistY);
	printf("mapX=%d\n", scene->mapX);
	printf("mapY=%d\n", scene->mapY);
	printf("stepX=%d\n", scene->stepX);
	printf("stepY=%d\n", scene->stepY);
	printf("perpWallDist=%f\n", scene->perpWallDist);
}
