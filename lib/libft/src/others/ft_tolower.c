/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:30:16 by lbastien          #+#    #+#             */
/*   Updated: 2022/10/11 16:38:56 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		c += 32;
	return (c);
}
/* Main
#include <stdio.h>
int	main(void)
{
	int c;
	char i;

	printf("Enter an integer :");
	scanf("%d", &c);
	printf("Your char is = %c\n", c);
	i = ft_tolower(c);
	printf("End Char = %c\n", i);
}
*/
