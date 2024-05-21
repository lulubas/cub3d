/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:22:04 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/21 16:21:33 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FCT_H
#define FCT_H

//Initialisation
t_data 	*init_data_struct(void);

//Parser
void	check_scene(int argc, char **argv, t_data *data);
void	parse_scene(t_data *data);
t_tile	**parse_list_to_array(t_list *lst, t_data *data);
t_list	*list_new(char *str);
void	list_addback(t_list *new, t_list **lst, t_data *data);

//Mlx, Raycast & Render
void	init_mlx(t_data *data);
int		raycast_and_render(t_data *data);
void	process_input(t_data *data);
void    init_rays(int x, int width, t_scene *scene);
void	perform_dda(t_scene *scene, t_tile **map);
void	split_slice(t_scene *scene);
void	draw_slice(int x, t_image *buffer, t_scene *scene, t_data *data);
t_image load_texture(t_scene *scene, t_data *data);
int		get_color(int texX, int texY, t_image *texture);
void	put_pixel(int pixel, int color, t_image *buffer);

//Utils and Print
void    print_data(t_data *data);
void    print_scene(t_scene *scene);
void	print_list(t_list *lst);
char	*tile_to_string(t_tile tile);

//Error, Free & Exit
void	ft_error(t_data *data, char *str, int status);
void	free_all(t_data *data);
void	free_2darray(char ***array);
void	free_list(t_list **lst);

#endif