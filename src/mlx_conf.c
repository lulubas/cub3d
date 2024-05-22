/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_conf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:22:56 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/22 16:59:43 by lbastien         ###   ########.fr       */
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
	int text_height;
	int text_width ;

	text_height = SCREEN_HEIGHT;
	text_width = SCREEN_WIDTH;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3d");
	if (!data->mlx || !data->win)
		ft_error(data, "Failed to initialise MLX", 1);
	mlx_hook(data->win, 2, 0, key_press, data);
	mlx_hook(data->win, 3, 0, key_release, data);
	mlx_hook(data->win, 17, 0, exit_hook, data);
	data->scene->no_img =  mlx_xpm_file_to_image(data->mlx, data->no_texture, &text_width, &text_height);
	if (!data->scene->no_img)
		ft_error(data, "Failed to load North Wall texture", 1);
	data->scene->so_img =  mlx_xpm_file_to_image(data->mlx, data->so_texture, &text_width, &text_height);
	data->scene->ea_img =  mlx_xpm_file_to_image(data->mlx, data->ea_texture, &text_width, &text_height);
	data->scene->we_img =  mlx_xpm_file_to_image(data->mlx, data->we_texture, &text_width, &text_height);
}