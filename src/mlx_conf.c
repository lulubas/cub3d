/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_conf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:22:56 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/24 01:00:42 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_hook(t_data *data)
{
	ft_error(data, "Exiting from input", 0);
	return (1);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == ESCAPE)
		ft_error(data, "Exiting from input", 0);
	if (keycode == KEY_W)
		data->up_pressed = true;
	if (keycode == KEY_A)
		data->left_pressed = true;
	if (keycode == KEY_S)
		data->down_pressed = true;
	if (keycode == KEY_D)
		data->right_pressed = true;
	if (keycode == ARROW_LEFT)
		data->left_rotate_pressed = true;
	if (keycode == ARROW_RIGHT)
		data->right_rotate_pressed = true;
	return (0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->up_pressed = false;
	if (keycode == KEY_A)
		data->left_pressed = false;
	if (keycode == KEY_S)
		data->down_pressed = false;
	if (keycode == KEY_D)
		data->right_pressed = false;
	if (keycode == ARROW_LEFT)
		data->left_rotate_pressed = false;
	if (keycode == ARROW_RIGHT)
		data->right_rotate_pressed = false;
	return (0);
}

void	init_mlx(t_data *data)
{
	int	tex_height;
	int	tex_width ;
	int	i;

	tex_height = SCREEN_HEIGHT;
	tex_width = SCREEN_WIDTH;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	if (!data->mlx || !data->win)
		ft_error(data, "Failed to initialise MLX", 1);
	mlx_hook(data->win, 2, 0, key_press, data);
	mlx_hook(data->win, 3, 0, key_release, data);
	mlx_hook(data->win, 17, 0, exit_hook, data);
	i = 0;
	while (i < 4)
	{
		data->textures_ptr[i] = mlx_xpm_file_to_image(data->mlx, \
			data->textures_path[i], &tex_width, &tex_height);
		i++;
	}
}
