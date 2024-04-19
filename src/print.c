/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 02:39:50 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/19 02:56:50 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    print_data(t_data *data)
{
    printf("---Data structure---\n");
    printf("filepath=%s\n", data->filepath);
    printf("no_texture=%s\n", data->no_texture);
    printf("so_texture=%s\n", data->so_texture);
    printf("ea_texture=%s\n", data->ea_texture);
    printf("we_texture=%s\n", data->we_texture);
}

void print_2darray(char **darray)
{
    int i;

    i = 0;
    while(darray[i])
    {
        printf("array[%d]:%s\n", i, darray[i]);
        i++;
    }
}