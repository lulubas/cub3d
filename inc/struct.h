/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:39:20 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/26 08:43:40 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

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
	void		*mlx;
	void		*win;
	int			posX;
	int			posY;
}	t_data;

#endif /* STRUCT_H */
