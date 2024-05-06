/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:45:05 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/06 15:39:05 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFFER_SIZE 42

//External libraries

# include<unistd.h>
# include<string.h>
# include<stdlib.h>
# include<stdarg.h>
#include <stdio.h>

//Libft functions
size_t	ft_strlen(const char *str);
void	ft_trimnl(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int 	ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
int		ft_putnbr(int nb);
int		ft_nbrlen(int n);
int		ft_putchar(char c);
int		ft_putstr(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
int	    ft_atoi(const char *str);

//Get_next_line
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_fail(char **str);

#endif
