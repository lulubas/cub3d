/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:59:26 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/19 03:22:10 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_and_exit(t_data *data, char *str, int status)
{
	if (data)
	{
		if (data->filepath)
			free(data->filepath);
		if (data->no_texture)
			free(data->no_texture);
		if (data->so_texture)
			free(data->so_texture);
		if (data->ea_texture)
			free(data->ea_texture);
		if (data->we_texture)
			free(data->we_texture);
		if (data->mlx)
			free(data->mlx);
		if (data->win)
			free(data->win);
	}
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit (status);
}

void	free_2darray(char ***array)
{
	int	i;

	i = 0;
	while ((*array)[i])
	{
		free((*array)[i]);
		i++;
	}
	free(*array);
	*array = NULL;
}
