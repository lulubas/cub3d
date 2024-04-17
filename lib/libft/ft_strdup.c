/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 16:03:21 by lbastien          #+#    #+#             */
/*   Updated: 2022/10/18 17:52:29 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_cpy(const char *str, char *ctr);

char	*ft_strdup(const char *str)
{
	size_t	n;
	char	*ctr;

	n = ft_strlen(str);
	ctr = (char *)malloc(sizeof(char) * (n + 1));
	if (!ctr)
		return (0);
	ft_strlcpy(ctr, str, n + 1);
	return (ctr);
}
/* Main
#include <stdio.h>
int	main(void)
{
	const char	str[50] = "Hello my name is lulu";

	printf("Expected result : %s\n", strdup(str));
	printf("Returned result : %s\n", ft_strdup(str));

	if (strcmp(strdup(str), ft_strdup(str)) == 0)
		printf("Both strings are the same ! Success !\n");
	free(strdup(str));
	free(ft_strdup(str));
	return(0);
}
*/
