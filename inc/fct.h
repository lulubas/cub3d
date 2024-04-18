/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:22:04 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/18 16:38:53 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FCT_H
#define FCT_H

t_data 	*init_data_struct(void);
void	free_and_exit(t_data *data, char *str, int status);
void	check_scene(int argc, char **argv, t_data *data);
void	parse_map(t_data *data);
void	init_game(t_data *data);
void	free_all(t_data *data);

#endif