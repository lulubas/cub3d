/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:56:09 by lbastien          #+#    #+#             */
/*   Updated: 2022/10/18 21:01:20 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*tmp;
	size_t	n;

	n = ft_strlen(s1);
	tmp = (char *)s1;
	while (*tmp && ft_strchr(set, *tmp))
	{
		tmp++;
		n--;
	}
	while (n && ft_strchr(set, tmp[n - 1]))
		n--;
	str = (char *)malloc(sizeof(char) * (n + 1));
	if (str == 0)
		return (0);
	ft_strlcpy(str, tmp, n + 1);
	return (str);
}
/* Main
#include<stdio.h>
int	main(void)
{
	char	s1[50] = "Hello louis \t";
	char	set[10] = "is \t";

	printf("The initial string is: \n%s\n", s1);
	printf("The chars to trim are: \n%s\n", set);
	printf("Result : \n%s\n", ft_strtrim(s1, set));
	free(ft_strtrim(s1, set));
	return (0);
}
*/
