/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:39:20 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/08 13:48:01 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

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

typedef enum s_walldir{
    NORTH,
	SOUTH,
	EAST,
	WEST
} t_walldir;

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

typedef struct s_scene
{
	double		playerPosX;
	double		playerPosY;
	double		playerDirX;
	double		playerDirY;
	double		rayDirX;
	double		rayDirY;
	double		planeX;
	double		planeY;
	double		sideDistX;
	double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	int			mapX;
	int			mapY;
	int			stepX;
	int			stepY;
	double		perpWallDist;
	int			drawStart;
	int			drawEnd;
	void		*no_img;
	void		*so_img;
	void		*ea_img;
	void		*we_img;

}	t_scene;

typedef struct s_data
{
	char 		*filepath;
	char		*no_texture;
	char		*so_texture;
	char		*ea_texture;
	char		*we_texture;
	int			F_color;
	int			C_color;
	int			map_x;
	int			map_y;
	t_list		*lst;
	t_tile		**map;
	t_scene		*scene;
	int			**buffer;
	void		*mlx;
	void		*win;
	void		*img_buffer;
	int			player_x;
	int			player_y;
	bool		up_pressed;
	bool		down_pressed;
	bool		left_pressed;
	bool		right_pressed;
}	t_data;

#endif /* STRUCT_H */
