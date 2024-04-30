/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:45:20 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/30 17:55:51 by damendez         ###   ########.fr       */
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
	check_map(data); // TO_DO
	//Use function below to print the content of data struct
	printf("hey");
	print_data(data);
	free_all(data);
	return (0);
}