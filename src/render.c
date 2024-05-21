/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:32:07 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/21 16:20:50 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	raycast_and_render(t_data *data)
{	
	int 		x;
	char		*img_buffer;
	t_image		buffer;

	x = 0;
	process_input(data);
	img_buffer = mlx_new_image(data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	buffer.image = mlx_get_data_addr(img_buffer, &buffer.pixel_bits, &buffer.line_bytes, &buffer.endian);
	while (x < SCREEN_WIDTH)
	{
		init_rays(x, SCREEN_WIDTH, data->scene);
		perform_dda(data->scene, data->map);
		split_slice(data->scene);
		draw_slice(x, &buffer, data->scene, data);
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, img_buffer, 0, 0);
	mlx_destroy_image(data->mlx, img_buffer);
	return (0);
}