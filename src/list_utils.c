/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbastien <lbastien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 01:41:06 by lbastien          #+#    #+#             */
/*   Updated: 2024/04/20 03:10:43 by lbastien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_list	*list_new(char *str)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->str = ft_strdup(str);
	lst->next = NULL;
	return (lst);
}

void	list_addback(t_list *new, t_list **lst, t_data *data)
{
	t_list	*tmp;
	
	if (!new)
		ft_error(data, "Failed to allocate list node", 1);
	tmp = *lst;
	if (!*lst)
		*lst = new;
	else
	{
		while(tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	free_node(t_list *node)
{
	if (node)
	{
		if (node->str)
			free(node->str);
		free(node);
	}
	node = NULL;
}

void	free_list(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		*lst = (*lst)->next;
		free_node(tmp);
		tmp = *lst;
	}
	lst = NULL;
}

void	print_list(t_list *lst)
{
	t_list *tmp;
	tmp = lst;
	while (tmp)
	{
		printf("%s", tmp->str);
		tmp = tmp->next;
	}
}