/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:18:21 by lbastien          #+#    #+#             */
/*   Updated: 2022/10/17 17:16:51 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*a;
	const unsigned char	*b;
	size_t				i;

	i = 0;
	a = (const unsigned char *)s1;
	b = (const unsigned char *)s2;
	while (i < n)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}
/* Main
#include <stdio.h>
int	main(void)
{
	char	src[50] = "aaaaa";
	char	dst[50] = "aaaaaa";
	size_t	n;

	printf("Enter n :");
	scanf("%zu", &n);
	printf("Source = %s\n", src);
	printf("Destination = %s\n", dst);
	printf("Return Value = %d\n", ft_memcmp(src, dst, n));
	printf("Expected Value = %d\n", memcmp(src, dst, n));
	return(0);
}
*/
