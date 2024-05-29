/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:22:04 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/29 14:16:07 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FCT_H
# define FCT_H

//Initialisation
t_data	*init_data_struct(void);

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
void	init_rays(int x, int width, t_scene *scene);
void	perform_dda(t_scene *scene, t_tile **map);
void	split_slice(t_scene *scene);
void	draw_slice(int x, t_image *buffer, t_data *data);
int		rgb_to_int(char **rgb);
t_image	load_texture_data(t_scene *scene, t_data *data);
int		get_color(int texX, int texY, t_image *texture);
void	put_pixel(int pixel, int color, t_image *buffer);

//Game Logic
void	move_forward(t_scene *scene, t_tile **map);
void	move_backward(t_scene *scene, t_tile **map);
void	move_left(t_scene *scene, t_tile **map);
void	move_right(t_scene *scene, t_tile **map);

//Utils and Print
void	print_data(t_data *data);
void	print_scene(t_scene *scene);
void	print_list(t_list *lst);
char	*tile_to_string(t_tile tile);

//Error, Free & Exit
void	ft_error(t_data *data, char *str, int status);
void	free_all(t_data *data);
void	free_2darray(char ***array);
void	free_tex_paths(char ***array);
void	free_tex_ptr(void ***array, t_data *data);
void	free_list(t_list **lst);

/*		checker		*/
void	ft_check_tex(t_data *data, char *texture_path);
void	check_scene(int argc, char **argv, t_data *data);
void	check_if_tex(t_data *data, char *line);
void	check_color(t_data *data, char *line);
int		is_map_line(char *line);
void	is_texorcolor(t_data *data, char *line, int *i);
void	check_map(t_data *data);

/*		checker_map.c		*/
void	check_player_count(t_data *data);
void	check_closed(t_data *data);
void	check_playable(t_data *data);

/*		utils.c		*/
void	skip_spaces(char *str);
void	free_split(char **split);
int		ft_strlen_n(const char *str);
int		ft_ptrlen(char **str);
int		is_num_or_space(char c);

/*		map_utils.c		*/
int		is_map_line(char *line);
int		is_player(char c);
int		all_ones(char *str);
int		is_surrounded_space_or_wall(t_data *data, int y, int x);

#endif