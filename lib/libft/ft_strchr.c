/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:52:35 by lbastien          #+#    #+#             */
/*   Updated: 2022/10/11 16:38:41 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	a;

	a = c;
	while (*str && *str != a)
		str++;
	if (*str != a)
		return (0);
	return ((char *)str);
}
/* Main
#include <stdio.h>
char*	ft_strchr(const char *str, int c);
int	main(void)
{
	char	str[50] = "This is a test string to try";
	char	str_t[50] = "This is a test string to try";
	int	c;
	char t;

	printf("The initial string is = %s\n", str);
	printf("Enter a char :");
	scanf(" %c", &t);
	c = t;
	printf("Your char int equivalent is = %d\n", c);
	printf("The end result is = %s\n", ft_strchr(str, c));
	printf("The expected result is = %s\n", strchr(str_t, c));
	return(0);
}
*/
