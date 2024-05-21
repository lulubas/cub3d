/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:19:03 by lbastien          #+#    #+#             */
/*   Updated: 2022/11/08 14:50:22 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*scan;

	if (!lst || !del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		scan = tmp;
		tmp = tmp->next;
		ft_lstdelone(scan, del);
	}	
	*lst = NULL;
}
