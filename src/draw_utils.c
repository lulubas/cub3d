/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:11:37 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/21 16:40:24 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_image load_texture(t_scene *scene, t_data *data)
{
	t_image texture;

	texture.image = NULL;
    texture.pixel_bits = 0;
    texture.line_bytes = 0;
    texture.endian = 0;
	if (scene->side == NORTH)
		texture.image = mlx_get_data_addr(scene->no_img, &texture.pixel_bits, &texture.line_bytes, &texture.endian);
	else if (scene->side == SOUTH)
		texture.image = mlx_get_data_addr(scene->so_img, &texture.pixel_bits, &texture.line_bytes, &texture.endian);
	else if (scene->side == EAST)
		texture.image = mlx_get_data_addr(scene->ea_img, &texture.pixel_bits, &texture.line_bytes, &texture.endian);
	else if (scene->side == WEST)
		texture.image = mlx_get_data_addr(scene->we_img, &texture.pixel_bits, &texture.line_bytes, &texture.endian);
	if (texture.image == NULL)
		ft_error(data, "Failed to load texture", 1);
	return (texture);
}

int		get_color(int texX, int texY, t_image *texture)
{
	int 	pixel_index;
	int		color;
	
	pixel_index = (texY * texture->line_bytes) + (texX * (texture->pixel_bits / 8));
    color = *(unsigned int *)(texture->image + pixel_index);
	return (color);
}

void	put_pixel(int pixel, int color, t_image *buffer)
{
	if (buffer->endian == 1)        // Most significant (Alpha) byte first
	{
		buffer->image[pixel + 0] = (color >> 24) & 0xFF;
		buffer->image[pixel + 1] = (color >> 16) & 0xFF;
		buffer->image[pixel + 2] = (color >> 8) & 0xFF;
		buffer->image[pixel + 3] = (color) & 0xFF;
	}
	else if (buffer->endian == 0)   // Least significant (Blue) byte first
	{
		buffer->image[pixel + 0] = (color) & 0xFF;
		buffer->image[pixel + 1] = (color >> 8) & 0xFF;
		buffer->image[pixel + 2] = (color >> 16) & 0xFF;
		buffer->image[pixel + 3] = (color >> 24);
	}
}