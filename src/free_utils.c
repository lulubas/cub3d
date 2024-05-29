/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 01:02:38 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/29 14:16:51 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	free_tex_paths(char ***array)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free((*array)[i]);
		i++;
	}
	free(*array);
	*array = NULL;
}

void	free_tex_ptr(void ***array, t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if ((*array)[i])
			mlx_destroy_image(data->mlx, (*array)[i]);
		i++;
	}
	free(*array);
	*array = NULL;
}
