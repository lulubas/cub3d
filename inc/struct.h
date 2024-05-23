/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:39:20 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/24 01:26:58 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef enum s_tile
{
	SPACE,
	WALL,
	EMPTY,
	P_NORTH,
	P_SOUTH,
	P_EAST,
	P_WEST
}	t_tile;

typedef enum s_walldir
{
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_walldir;

typedef struct s_image
{
	char	*image;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
}	t_image;

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

typedef struct s_scene
{
	double		player_posx;
	double		player_posy;
	double		player_dirx;
	double		player_diry;
	double		ray_dirx;
	double		ray_diry;
	double		plane_x;
	double		plane_y;
	double		side_distx;
	double		side_disty;
	double		delta_distx;
	double		delta_disty;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	t_walldir	side;
	double		perp_walldist;
	int			line_height;
	int			draw_start;
	int			draw_end;
}	t_scene;

typedef struct s_data
{
	char		*filepath;
	char		**textures_path;
	void		**textures_ptr;
	int			floor_color;
	int			ceiling_color;
	int			map_size_x;
	int			map_size_y;
	t_list		*lst;
	t_tile		**map;
	t_scene		*scene;
	int			**buffer;
	void		*mlx;
	void		*win;
	int			player_x;
	int			player_y;
	bool		up_pressed;
	bool		down_pressed;
	bool		left_pressed;
	bool		right_pressed;
	bool		left_rotate_pressed;
	bool		right_rotate_pressed;
}	t_data;

#endif /* STRUCT_H */
