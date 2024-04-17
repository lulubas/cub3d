/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:45:05 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/17 17:44:49 by lbastien         ###   ########.fr       */
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
int		ft_putnbr(int nb);
int		ft_nbrlen(int n);
int		ft_putchar(char c);
int		ft_putstr(char *s);

//Printf
typedef struct s_sc
{
	va_list	arg;
	int		len;
	int		width;
	int		error;
}				t_sc;
int		ft_printf(char const *format, ...);
int		pf_arg_c(t_sc *sc);
int		pf_arg_d(t_sc *sc);
int		pf_arg_d(t_sc *sc);
int		pf_arg_p(t_sc *sc);
int		pf_arg_s(t_sc *sc);
int		pf_arg_u(t_sc *sc);
int		pf_arg_x(t_sc *sc, char c);
int		pf_search_arg(const char format, t_sc *sc);
int		pf_read_text(t_sc *sc, char format);

//Get_next_line
char	*ft_strchr_gnl(char *s, int c);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_fail(char **str);

#endif
