/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:22:04 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/19 03:18:29 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FCT_H
#define FCT_H

t_data 	*init_data_struct(void);
void	free_and_exit(t_data *data, char *str, int status);
void	check_scene(int argc, char **argv, t_data *data);
void	parse_scene(t_data *data);
void    get_walls_texture(int fd, t_data *data);
void	init_game(int fd, t_data *data);
void	free_all(t_data *data);
void	free_2darray(char ***array);
void    print_data(t_data *data);
void    print_2darray(char **darray);

#endif