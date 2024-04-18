/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 17:56:04 by lbastien          #+#    #+#             */
/*   Updated: 2022/10/11 16:34:17 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
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
	ft_putstr_fd(str, fd);
	return (0);
}
*/
