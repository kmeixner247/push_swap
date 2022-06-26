/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <kmeixner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:40:32 by kmeixner          #+#    #+#             */
/*   Updated: 2022/04/06 18:03:15 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	nextmin(t_list **list, int oldmin)
{
	t_list	*tmp;
	long	min;

	min = 2147483648;
	tmp = *list;
	while (tmp)
	{
		if (tmp->content < min && tmp->content > oldmin)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

t_list	*find_position(t_list **list, int n)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->content == n)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

void	index_list(int listsize, t_list **list)
{
	int		n;
	int		min;
	t_list	**arr;

	n = 0;
	min = -2147483648;
	arr = malloc(sizeof(t_list **) * listsize);
	while (n < listsize)
	{
		min = nextmin(list, min);
		arr[n] = find_position(list, min);
		n++;
	}
	n = 0;
	while (n < listsize)
	{
		arr[n]->content = n + 1;
		n++;
	}
	free(arr);
}
