/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:48:53 by lbastien          #+#    #+#             */
/*   Updated: 2022/10/18 20:48:25 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_count(long int n)
{
	int	c;

	c = 0;
	if (n <= 0)
	{
		c++;
		n *= -1;
	}
	while (n)
	{
		n /= 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int m)
{
	char		*str;
	long int	n;
	int			i;
	int			j;

	j = 0;
	n = m;
	i = ft_count(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (0);
	str[i] = 0;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		j++;
	}
	while (i - j > 0)
	{
		str[i - 1] = n % 10 + 48;
		n /= 10;
		i--;
	}
	return (str);
}
/* Main
#include<stdio.h>
int	main(void)
{
	int	n;

	n = 125434;
	printf("The number is: %d\n", n);
	printf("The resulted string is: >%s<\n", ft_itoa(n));
	return (0);
}
*/
