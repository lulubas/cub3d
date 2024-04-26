/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:45:20 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/26 08:54:50 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int argc, char **argv)
{
	t_data	*data;

	data = init_data_struct();
	if (!data)
		return (1);
	check_scene(argc, argv, data);
	parse_scene(data);
	render_scene(data);
	//Use function below to print the content of data struct
	print_data(data);
	free_all(data);
	return (0);
}