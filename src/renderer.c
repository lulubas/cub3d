/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 17:35:15 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/04 20:40:52 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int exit_hook(t_data *data)
{
    ft_error(data, "Exiting from input", 0);
	return (1);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
		ft_error(data, "Exiting from input", 0);
	if (keycode == ARROW_UP)
		data->up_pressed = true;
	if (keycode == ARROW_DOWN)
		data->down_pressed = true;
	if (keycode == ARROW_LEFT)
		data->left_pressed = true;
	if (keycode == ARROW_RIGHT)
		data->right_pressed = true;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == ARROW_UP)
		data->up_pressed = false;
	if (keycode == ARROW_DOWN)
		data->down_pressed = false;
	if (keycode == ARROW_LEFT)
		data->left_pressed = false;
	if (keycode == ARROW_RIGHT)
		data->right_pressed = false;
	return (0);
}

void	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->width, data->height, "cub3d");
	if (!data->mlx || !data->win)
		ft_error(data, "Failed to initialise MLX", 1);
	mlx_hook(data->win, 2, 0, key_press, data);
	mlx_hook(data->win, 3, 0, key_release, data);
	mlx_hook(data->win, 17, 0, exit_hook, data);
}

void	render_scene(t_data *data)
{
	init_mlx(data);
	mlx_loop_hook(data->mlx, raycast_and_render, data);
	mlx_loop(data->mlx);
}