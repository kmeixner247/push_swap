/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:49:28 by kmeixner          #+#    #+#             */
/*   Updated: 2022/04/07 11:23:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

void	push(t_list **origin, t_list **target)
{
	t_list	*tmp;

	if (!*origin)
		return ;
	tmp = ft_lstnew((*origin)->content);
	if (*target)
		tmp->next = *target;
	*target = tmp;
	tmp = *origin;
	*origin = (*origin)->next;
	free(tmp);
}

void	swap(t_list **list)
{
	int		i;
	t_list	*tmplist;

	tmplist = *list;
	if (!tmplist || !tmplist->next)
		return ;
	i = tmplist->content;
	tmplist->content = tmplist->next->content;
	tmplist->next->content = i;
}

void	rotate(t_list **list)
{
	t_list	*lst;
	t_list	*tmp;

	lst = *list;
	tmp = *list;
	if (!lst || !lst->next)
		return ;
	if (!lst->next->next)
	{
		swap(list);
		return ;
	}
	*list = lst->next;
	while (lst->next)
		lst = lst->next;
	lst->next = tmp;
	tmp->next = NULL;
}

void	reverse_rotate(t_list **list)
{
	t_list	*lst;
	t_list	*tmp;

	lst = *list;
	tmp = *list;
	if (!lst || !lst->next)
		return ;
	if (!lst->next->next)
	{
		swap(list);
		return ;
	}
	while (lst->next->next)
		lst = lst->next;
	*list = lst->next;
	lst->next->next = tmp;
	lst->next = NULL;
}
