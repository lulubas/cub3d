/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 15:07:35 by lbastien          #+#    #+#             */
/*   Updated: 2022/10/11 16:42:50 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char	*ctr;

	ctr = (unsigned char *) str;
	while (n > 0)
	{
		*ctr = 0;
		ctr++;
		n--;
	}
}
/* Main
#include<stdio.h>
int	main(void)
{
	char	str[50] = "Hello my name is lulu";
	size_t	n;

	printf("Enter n :");
	scanf("%zu", &n);
	printf("String = %s\n", str);
	ft_bzero(str, n);
	printf("String = %c\n", *(str+8));
	return(0);
}
*/
