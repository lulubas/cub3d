/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:45:30 by agheredi          #+#    #+#             */
/*   Updated: 2024/04/17 17:33:03 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_arg_d(t_sc *sc)
{
	int	d;

	d = va_arg(sc->arg, int);
	if (ft_putnbr(d) == -1)
	{
		sc->error = -1;
		return (-1);
	}
	sc -> len += ft_nbrlen(d);
	return (1);
}
