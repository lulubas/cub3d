/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:11:37 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/24 16:50:22 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	rgb_to_int(char **rgb)
{
	int	red;
	int	green;
	int	blue;
	int	color;

	red = ft_atoi(rgb[0]) << 16;
	green = ft_atoi(rgb[1]) << 8;
	blue = ft_atoi(rgb[2]);
	color = (red | green | blue);
	free(rgb);
	return (color);
}

t_image	load_texture_data(t_scene *scene, t_data *data)
{
	t_image	texture;
	void	*image_ptr;

	image_ptr = NULL;
	if (scene->side == NORTH)
		image_ptr = data->textures_ptr[0];
	else if (scene->side == SOUTH)
		image_ptr = data->textures_ptr[1];
	else if (scene->side == EAST)
		image_ptr = data->textures_ptr[2];
	else if (scene->side == WEST)
		image_ptr = data->textures_ptr[3];
	if (!image_ptr)
		ft_error(data, "Invalid texture side", 1);
	texture.image = mlx_get_data_addr(image_ptr, &texture.pixel_bits, \
					&texture.line_bytes, &texture.endian);
	if (texture.image == NULL)
		ft_error(data, "Failed to get texture data", 1);
	return (texture);
}

int	get_color(int texX, int texY, t_image *texture)
{
	int	pixel_index;
	int	color;

	pixel_index = (texY * texture->line_bytes) + \
					(texX * (texture->pixel_bits / 8));
	color = *(unsigned int *)(texture->image + pixel_index);
	return (color);
}

void	put_pixel(int pixel, int color, t_image *buffer)
{
	if (buffer->endian == 1)
	{
		buffer->image[pixel + 0] = (color >> 24) & 0xFF;
		buffer->image[pixel + 1] = (color >> 16) & 0xFF;
		buffer->image[pixel + 2] = (color >> 8) & 0xFF;
		buffer->image[pixel + 3] = (color) & 0xFF;
	}
	else if (buffer->endian == 0)
	{
		buffer->image[pixel + 0] = (color) & 0xFF;
		buffer->image[pixel + 1] = (color >> 8) & 0xFF;
		buffer->image[pixel + 2] = (color >> 16) & 0xFF;
		buffer->image[pixel + 3] = (color >> 24);
	}
}
