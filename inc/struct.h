/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:39:20 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/30 18:51:20 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

typedef enum s_tile
{
	SPACE,
	WALL,
	EMPTY,
	NORTH,
	SOUTH,
	EAST,
	WEST
}	t_tile;

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	char 		*filepath;
	char		*no_texture;
	char		*so_texture;
	char		*ea_texture;
	char		*we_texture;
	char		**F_color;
	char		**C_color;
	int			map_x;
	int			map_y;
	t_list		*lst;
	t_tile		**map;
	int			res_width;
	int			res_length;
	void		*mlx;
	void		*win;
	double		posX;
	double		posY;
	int			mapX;
	int			mapY;
	int			dirX;
	int			dirY;
	int			planeX;
	int			planeY;
	double		camX;
	double		rayDirX;
	double		rayDirY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	int			stepX;
	int			stepY;
	int			time;
	int			old_time;
}	t_data;

#endif /* STRUCT_H */
