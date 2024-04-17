/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:45:20 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/17 18:31:06 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(void)
{
	t_data	*data;
	// char 	*filepath;

	data = init_data_struct();
	if (!data)
		return (1);
	ft_printf("Structure created\n");
	// check_map(argc, argv, data);
	// parse_map(data);
	// init_game(data);
	// free_all(data);
	return (0);
}