/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:07:04 by lbastien          #+#    #+#             */
/*   Updated: 2022/10/18 17:23:57 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *hay, const char *nee, size_t n)
{
	const char	*h_tmp;
	const char	*n_tmp;
	size_t		m;

	n_tmp = nee;
	h_tmp = hay;
	if (*nee == 0)
		return ((char *)hay);
	while (*hay && n > 0)
	{
		h_tmp = hay;
		n_tmp = nee;
		m = 0;
		while (*h_tmp && *h_tmp == *n_tmp && (n - m) > 0)
		{
			h_tmp++;
			n_tmp++;
			m++;
		}
		if (*n_tmp == 0)
			return ((char *)hay);
		hay++;
		n--;
	}
	return (0);
}
/* Main
#include <stdio.h>
int	main(void)
{
	char	haystack[] = "aaabcabcd";
	char	needle[] = "b";
	size_t	n;

	printf("Enter n=");
	scanf("%zu", &n);
	printf("\nHaystack is = %s\n", haystack);
	printf("Needle = %s\n", needle);
	printf("Returned Value = %s\n", ft_strnstr(haystack, needle, n));
	printf("Expected Value = %s\n", strnstr(haystack, needle, n));

	if (!strcmp(ft_strnstr(haystack, needle, n), strnstr(haystack, needle, n)))
		printf("\nSuccess !! Well done !!\n");
	return(0);
}
*/
