/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:59:26 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/18 16:22:50 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_and_exit(t_data *data, char *str, int status)
{
	if (data)
	{
		if (data->filepath)
			free(data->filepath);
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
