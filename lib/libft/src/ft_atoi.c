/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:40:21 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/24 14:36:08 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	r;
	int	n;

	r = 0;
	n = 1;

	while (ft_isspace(*str))
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			n *= -1;
		str++;
	}
	while (*str && *str > 47 && *str < 58)
	{
		r = (*str - 48) + (r * 10);
		str++;
	}
	return (r * n);
}

