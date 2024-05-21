/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:15:13 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/18 22:16:08 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strcmp(const char *s1, const char *s2) 
{
    while (*s1 && (*s1 == *s2))
	{
        s1++;
        s2++;
    }
    return ((unsigned char)*s1 - (unsigned char)*s2);
}