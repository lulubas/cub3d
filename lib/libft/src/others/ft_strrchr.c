/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:19:49 by lbastien          #+#    #+#             */
/*   Updated: 2022/10/14 17:31:09 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	a;
	char	*tmp;
	size_t	i;
	size_t	j;

	j = 0;
	a = c;
	tmp = (char *)str;
	i = ft_strlen(tmp) + 1;
	while (j < i - 1)
	{
		tmp++;
		j++;
	}
	while (i > 0 && *tmp != a)
	{
		tmp--;
		i--;
	}
	if (i == 0)
		return (0);
	return (tmp);
}
/* Main
#include <stdio.h>
int	main(void)
{
	char	str[50] = "bonjour";
	char	str_t[50] = "bonjour";
	int	c;
	char t;

	printf("The initial string is = %s\n", str);
	printf("Enter a char :");
	scanf(" %c", &t);
	c = t;
	printf("Your char int equivalent is = %d\n", c);
	printf("The end result is = %s\n", ft_strrchr(str, c));
	printf("The expected result is = %s\n", strrchr(str_t, c));
	return(0);
}
*/
