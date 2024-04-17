/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:45:20 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/17 16:25:28 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(void)
{
	t_data	*data;
	// char 	*filepath;

	data = init_data_struct();
	if (!data)
	ft_printf("Structure creeated\n");
		return (1);
	// check_map(argc, argv, data);
	// parse_map(data);
	// init_game(data);
	// free_all(data);
	return (0);
}