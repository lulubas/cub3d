/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:18:50 by damendez          #+#    #+#             */
/*   Updated: 2024/04/23 18:06:19 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		++i;
	}
	free(split);
}

int	ft_ptrlen(char **str)
{
	int	len;

	len = 0;
	while (str[len] != NULL)
	{
		++len;
	}
	return (len);
}

int	ft_strlen_n(const char *str)
{
	int	len;

	len = 0;
	while (*str != '\0' && *str != ' ')
	{
		++str;
		++len;
	}
	return (len);
}