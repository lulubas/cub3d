/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 15:35:11 by lbastien          #+#    #+#             */
/*   Updated: 2022/10/14 17:35:10 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;
	unsigned int	n;

	n = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * n + 1);
	if (!str)
		return (0);
	i = 0;
	while (i < n)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
/* Main
#include<stdio.h>
char	ft_alphatoindex(unsigned int i, char a)
{
	if (ft_isalpha(a))
		a = i + 48;
	return (a);
}

int	ft_isalpha(unsigned char a)
{
	if ((a < 'A' || a > 'Z') && (a < 'a' || a > 'z'))
		return (0);
	return (1);
}

int	main(void)
{
	char	s[20] = "abc abc";
	
	printf("Initial string is: %s\n", s);
	printf("Returned string is: %s\n", ft_strmapi(s, ft_alphatoindex));
	free(ft_strmapi(s, ft_alphatoindex));
}
*/
