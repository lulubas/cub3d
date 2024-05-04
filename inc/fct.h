/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:22:04 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/04 15:59:04 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FCT_H
#define FCT_H

t_data 	*init_data_struct(void);
void	ft_error(t_data *data, char *str, int status);
void	check_scene(int argc, char **argv, t_data *data);
void	parse_scene(t_data *data);
t_tile	**parse_list_to_array(t_list *lst, t_data *data);
void	render_scene(t_data *data);
int		raycast_and_render(t_data *data);
void	process_input(t_data *data);
void	free_all(t_data *data);
void	free_2darray(char ***array);
void    print_data(t_data *data);
void	print_list(t_list *lst);
char	*tile_to_string(t_tile tile);
t_list	*list_new(char *str);
void	list_addback(t_list *new, t_list **lst, t_data *data);
void	free_list(t_list **lst);

#endif