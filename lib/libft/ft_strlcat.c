/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:59:12 by lbastien          #+#    #+#             */
/*   Updated: 2022/11/08 16:52:21 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	srcl;
	size_t	dstl;

	i = 0;
	srcl = ft_strlen(src);
	dstl = ft_strlen(dst);
	if (n <= dstl)
		return (srcl + n);
	while (src[i] && (dstl + i) < n - 1)
	{
		dst[dstl + i] = src[i];
		i++;
	}
	dst[dstl + i] = 0;
	return (srcl + dstl);
}
/* Main
#include <stdio.h>
int	main(void)
{
	char	src[50] = "hello my name is lulu the bas";
	char	dst[50] = "that is the destination";
	char	*dest;
	
	dest = (char *)malloc(sizeof(*dest) * 15);
	memset(dest, 'r', 15);
	ft_strlcat(dest, "lorem ipsum dolor sit amet", 5);

	char	src_t[50] = "hello my name is lulu the bas";
	char	dst_t[50] = "that is the destination";
	size_t	n;
	int r;
	int	r_t;
	int new;

	printf("Enter n :");
	scanf("%zu", &n);
	printf("Source = %s\n", src);
	printf("Destination = %s\n", dst);
	r = ft_strlcat(dst, src, n);
	r_t = strlcat(dst_t, src_t, n);
	new = ft_strlcat(dest, "lorem ipsum dolor sit amet", 5);
	printf("New destination = %s\n", dst);
	printf("Return Value = %d\n", r);
	printf("Expected destination = %s\n", dst_t);
	printf("Expected Value = %d\n", r_t);
	write(1, "\n", 1);
	write(1, dest, 15),
	write(1, "\n", 1);
	printf("new is %d\n", new);

	return(0);
}
*/
