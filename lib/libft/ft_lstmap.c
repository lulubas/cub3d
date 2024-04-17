/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:23:43 by lbastien          #+#    #+#             */
/*   Updated: 2022/11/08 17:46:11 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*scan;
	t_list	*n_lst;
	t_list	*n_node;

	if (!f || !del || !lst)
		return (0);
	n_lst = ft_lstnew(f(lst->content));
	if (!n_lst)
		return (0);
	scan = lst->next;
	while (scan)
	{
		n_node = ft_lstnew(f(scan->content));
		if (!n_node)
		{
			ft_lstclear(&n_lst, del);
			return (0);
		}
		ft_lstadd_back(&n_lst, n_node);
		scan = scan->next;
	}
	return (n_lst);
}
