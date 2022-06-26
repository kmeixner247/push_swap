/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <kmeixner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:37:46 by kmeixner          #+#    #+#             */
/*   Updated: 2022/04/06 17:59:45 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (!temp)
	{
		*lst = new;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	return ;
}

t_list	*ft_lstnew(int content)
{
	t_list	*newlist;

	newlist = malloc(sizeof(t_list));
	if (!newlist)
		return (NULL);
	newlist->content = content;
	newlist->next = (NULL);
	return (newlist);
}

int	listsize(t_list **list)
{
	int		counter;
	t_list	*tmp;

	counter = 0;
	tmp = *list;
	while (tmp)
	{
		counter++;
		tmp = tmp->next;
	}
	return (counter);
}

int	listmax(t_list **list)
{
	t_list	*tmp;
	int		max;

	max = 0;
	tmp = *list;
	while (tmp)
	{
		if (tmp->content > max)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

int	listmin(t_list **list)
{
	t_list	*tmp;
	int		min;

	min = 2147483647;
	tmp = *list;
	while (tmp)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}
