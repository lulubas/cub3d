/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:21:33 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/24 01:33:00 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling(int x, int *y, t_image *buffer, t_data *data)
{
	int	pixel;

	while (*y < data->scene->draw_start)
	{
		pixel = (*y * buffer->line_bytes) + (x * 4);
		put_pixel(pixel, data->ceiling_color, buffer);
		(*y)++;
	}
}

int	get_tex_x(t_scene *scene)
{
	int		tex_x;
	double	wall_x;

	if (scene->side == EAST || scene->side == WEST)
		wall_x = scene->player_posy + (scene->ray_diry * scene->perp_walldist);
	else
		wall_x = scene->player_posx + (scene->ray_dirx * scene->perp_walldist);
	wall_x -= (int)wall_x;
	tex_x = (int)(wall_x * (double)TEXTURE_WIDTH);
	if ((scene->side == EAST || scene->side == WEST) && scene->ray_dirx > 0)
		tex_x = TEXTURE_WIDTH - tex_x - 1;
	else if ((scene->side == NORTH || scene->side == SOUTH) \
				&& scene->ray_diry > 0)
		tex_x = TEXTURE_WIDTH - tex_x - 1;
	return (tex_x);
}

void	draw_wall(int x, int *y, t_image *buffer, t_data *data)
{
	int		tex_y;
	int		pixel;
	double	tex_step;
	double	tex_pos;
	t_image	texture;

	tex_step = 1.0 * TEXTURE_HEIGHT / data->scene->line_height;
	tex_pos = (data->scene->draw_start - SCREEN_HEIGHT / 2 \
				+ data->scene->line_height / 2) * tex_step;
	while (*y < data->scene->draw_end)
	{
		tex_y = (int)tex_pos % TEXTURE_HEIGHT;
		tex_pos += tex_step;
		pixel = (*y * buffer->line_bytes) + (x * 4);
		texture = load_texture_data(data->scene, data);
		put_pixel(pixel, get_color(get_tex_x(data->scene), tex_y, &texture), \
			buffer);
		(*y)++;
	}
}

void	draw_floor(int x, int *y, int color, t_image *buffer)
{
	int	pixel;

	while (*y < SCREEN_HEIGHT)
	{
		pixel = (*y * buffer->line_bytes) + (x * 4);
		put_pixel(pixel, color, buffer);
		(*y)++;
	}
}

//Calculate how the wall length to print on the verical line
void	draw_slice(int x, t_image *buffer, t_data *data)
{
	int	y;

	y = 0;
	draw_ceiling(x, &y, buffer, data);
	draw_wall(x, &y, buffer, data);
	draw_floor(x, &y, data->floor_color, buffer);
}
