/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:39:20 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/18 21:55:23 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
#define STRUCT_H

typedef struct s_data
{
	char 		*filepath;
	char		*no_texture;
	char		*so_texture;
	char		*ea_texture;
	char		*we_texture;
	void		*mlx;
	void		*win;
}	t_data;

#endif
