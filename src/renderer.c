/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:35:15 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/26 09:20:00 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int exit_hook(t_data *data)
{
    ft_error(data, "Exiting from input", 0);
	return (1);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
		ft_error(data, "Exiting from input", 0);
	return (0);
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1200, 800, "cub3d");
	if (!data->mlx || !data->win)
		ft_error(data, "Failed to initialise MLX", 1);
	mlx_key_hook(data->win, &key_hook, data);
	mlx_hook(data->win, 17, 0, exit_hook, data);
}

void	render_scene(t_data *data)
{
	init_mlx(data);
	raycast_and_render(data);
	// while (1)
	// {
	// 	mlx_clear_window(data->mlx, data->win);
	// 	raycast_and_render(data);
	// }
	mlx_loop(data->mlx);
}