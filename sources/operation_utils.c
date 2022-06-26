/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <kmeixner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:49:28 by kmeixner          #+#    #+#             */
/*   Updated: 2022/04/06 17:59:56 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_list **origin, t_list **target)
{
	t_list	*tmp;

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

void	smart_rotate(t_list **stack_a, int n)
{
	int		pos;
	t_list	*tmp;

	pos = 1;
	tmp = *stack_a;
	while (tmp->content != n)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos <= listsize(stack_a) / 2 + 1)
	{
		while (pos > 1)
			pos -= ra(stack_a);
	}
	else if (pos > listsize(stack_a) / 2)
	{
		while (pos <= listsize(stack_a))
			pos += rra(stack_a);
	}
}
