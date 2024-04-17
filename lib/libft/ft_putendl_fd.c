/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:13:32 by lbastien          #+#    #+#             */
/*   Updated: 2022/10/11 17:35:17 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putendl_fd(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	ft_putchar_fd('\n', fd);
}
/* Main
#include<stdio.h>
#include <fcntl.h>
int	main(void)
{
 	int fd;
	char *str;

	str = "Coucou";
	fd = open("test", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	printf("fd=%d\n Check content of file 'test'\n", fd);
	if (fd==-1)
		printf("Error open() number=%d\n", fd);
	ft_putendl_fd(str, fd);
	return (0);
}
*/
