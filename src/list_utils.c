/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damendez <damendez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 01:41:06 by lbastien          #+#    #+#             */
/*   Updated: 2024/05/07 18:30:44 by damendez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static char	*add_map_row(char *str, int map_x)
// {
// 	char	*tmp;
// 	int		i;
// 	int		j;

// 	tmp = (char *)malloc(sizeof(char) * (map_x + 1));
// 	if (!tmp)
// 		return (0);
// 	i = 0;
// 	j = 0;
// 	tmp[j] = ' ';
// 	while (str[i] != '\0')
// 	{
// 		tmp[j] = str[i];
// 		j++;
// 		i++;
// 	}
// 	tmp[j] = ' ';
// 	tmp[++j] = '\0';
// 	return (tmp);
// }

t_list	*list_new(char *str /*, t_data *data*/)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->str = ft_strdup(str);
	printf("lst->str: %s\n", lst->str);
	//lst->str = add_map_row(str, data->map_x);
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