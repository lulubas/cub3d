/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:39:20 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/04 12:05:17 by lbastien         ###   ########.fr       */
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
	int			width;
	int			height;
	void		*mlx;
	void		*win;
	int			player_x;
	int			player_y;
	double		playerPosX;
	double		playerPosY;
	int			mapX;
	int			mapY;
	int			playerDirX;
	int			playerDirY;
	double		planeX;
	double		planeY;
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
