/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:38:55 by lbastien          #+#    #+#             */
/*   Updated: 2022/10/18 15:45:42 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dst;
	if (!d && !s)
		return (NULL);
	while (n > 0)
	{
		*d = *s;
		s++;
		d++;
		n--;
	}
	return (dst);
}
/* Main
#include <stdio.h>
int	main(void)
{
	char	src[50] = "hello my name is lulu";
	char	dst[50] = "that is the destination";
	char	src_t[50] = "hello my name is lulu";
	char	dst_t[50] = "that is the destination";

	size_t	n;

	printf("Enter n :");
	scanf("%zu", &n);
	printf("Source = %s\n", src);
	printf("Destination = %s\n", dst);
	printf("New destination = %s\n", ft_memcpy(dst, src, n));
	printf("Expected destination = %s\n", memcpy(dst_t, src, n));
	if (!strcmp(ft_memcpy(dst, src, n), memcpy(dst_t, src_t, n)))
			printf("Success dude !\n");
	return(0);
}
*/
