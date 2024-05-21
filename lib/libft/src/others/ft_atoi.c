/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:40:21 by lbastien          #+#    #+#             */
/*   Updated: 2022/10/12 21:09:20 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	r;
	int	n;

	r = 0;
	n = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			n *= -1;
		str++;
	}
	while (*str && *str > 47 && *str < 58)
	{
		r = (*str - 48) + (r * 10);
		str++;
	}
	return (r * n);
}

/* Main
#include <stdio.h>
int	main(void)
{
	char	str[50];
	
	printf("Enter the string to try : ");
	scanf("%s", str);
	printf("Returned Value = %d\n", ft_atoi(str));
	printf("Expected Value = %d\n", atoi(str));

	if (ft_atoi(str) == atoi(str))
		printf("\nSuccess !! Well done !!\n");
	return(0);
}
*/
