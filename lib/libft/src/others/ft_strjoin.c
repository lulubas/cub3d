/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:55:40 by lbastien          #+#    #+#             */
/*   Updated: 2022/10/18 20:50:17 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	n;
	size_t	n1;
	size_t	n2;

	n1 = ft_strlen((char *)s1);
	n2 = ft_strlen((char *)s2);
	n = n1 + n2;
	str = (char *)malloc(sizeof(char) * n + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, s1, n1 + 1);
	ft_strlcat(str, s2, n + 1);
	return (str);
}
/* Main
#include <stdio.h>
int	main(void)
{
	char	s1[50] = "hello my name is lulu the bas";
	char	s2[50] = "that is the destination";

	printf("Prefix string = %s\n", s1);
	printf("Suffix string = %s\n", s2);
	printf("New string = %s\n", ft_strjoin(s1, s2));
	return(0);
}
*/
