/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:25:32 by lbastien          #+#    #+#             */
/*   Updated: 2022/10/17 21:28:53 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//
void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	a;
	unsigned char	*s;

	a = c;
	s = (unsigned char *)str;
	while (*s != a && n > 1)
	{
		s++;
		n--;
	}
	if (*s != a || n == 0)
		return (0);
	return ((void *)s);
}
/*
void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	a;
	unsigned char	*s;

	a = c;
	s = (unsigned char *)str;
	while (n > 0)
	{
		if (*s == a)
			return ((void *)s);
		n--;
		s++;
	}
	return (0);
}
*/

/* Main
#include <stdio.h>
int	main(void)
{
	char	str[] = "abcde";
//	char	str[] = {0, 1, 2, 3, 4 ,5};
	int	c;
	char	t;
	size_t	n;

	printf("The initial string is = %s\n", str);
	printf("Enter a char :");
	scanf(" %c", &t);
	printf("Enter n :");
	scanf("%zu", &n);
	c = t;
	printf("Your char int equivalent is = %d\n", c);
	printf("The end result is = %s\n", ft_memchr(str, c, n));
	printf("The expected result is = %s\n", memchr(str, c, n));
	return(0);
}
*/
