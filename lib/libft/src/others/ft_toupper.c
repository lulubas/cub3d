/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:01:41 by lbastien          #+#    #+#             */
/*   Updated: 2022/11/08 15:38:13 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c > 96 && c < 123)
		c -= 32;
	return (c);
}
/* Main
#include <stdio.h>
int	main(void)
{
	int c;
	char i;

	printf("Enter an integer :");
	scanf("%d", &c);
	printf("Your char is = %c\n", c);
	i = ft_toupper(c);
	printf("End Char = %c\n", i);
}
*/
