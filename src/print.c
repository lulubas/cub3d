/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 02:39:50 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/30 17:56:55 by damendez         ###   ########.fr       */
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
	printf("F_color=");
	print_2darray(data->F_color);
	printf("C_color=");
	print_2darray(data->C_color);
	printf("map_x=%d\n", data->map_x);
	printf("map_y=%d\n", data->map_y);
	printf("-----MAP ARRAY------\n");
	print_map(data);
	printf("--------------------\n");
	printf("====================\n");
	// int		i;
	// t_list	*tmp;

	// tmp = data->lst;
	// while (tmp != NULL)
	// {
	// 	printf("jdjid");
	// 	i = 0;
	// 	while (tmp->str[i] != '\0')
	// 	{
	// 		printf("%c char", tmp->str[i]);
	// 		i++;
	// 	}
	// 	tmp = tmp->next;
	// 	printf("\n");
	// }
}
