/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <kmeixner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 17:58:23 by kmeixner          #+#    #+#             */
/*   Updated: 2022/04/06 23:03:45 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	quicksort_reverse(t_list **stack_a, t_list **stack_b, int min, int max)
{
	int	pivot;

	pivot = min + (max - min) / 2;
	if (max - min < 10)
	{
		if (max - min >= 5)
		{
			simple_pr_a(stack_a, stack_b, max - 4, max);
			sort_five(stack_a, stack_b, 5);
			simple_pr_a(stack_a, stack_b, min, max - 5);
			sort_five(stack_a, stack_b, max - min - 4);
		}
		else
		{
			simple_pr_a(stack_a, stack_b, min, max);
			sort_five(stack_a, stack_b, max - min + 1);
		}
		return ;
	}
	if (max - pivot + 1 >= 1)
		pushrange_a(stack_a, stack_b, pivot + 1, max);
	else
		simple_pr_a(stack_a, stack_b, pivot + 1, max);
	quicksort(stack_a, stack_b, pivot + 1, max);
	quicksort_reverse(stack_a, stack_b, min, pivot);
}

void	quicksort(t_list **stack_a, t_list **stack_b, int min, int max)
{
	int	pivot;

	pivot = min + (max - min) / 2;
	if (max - min < 10)
	{
		if (max - min >= 5)
		{
			simple_pr_b(stack_a, stack_b, min, max - 5);
			sort_five(stack_a, stack_b, 5);
			simple_pr_a(stack_a, stack_b, min, max - 5);
			sort_five(stack_a, stack_b, max - min - 4);
		}
		else
			sort_five(stack_a, stack_b, max - min + 1);
		return ;
	}
	if (pivot - min >= 20)
		pushrange_b(stack_a, stack_b, min, pivot);
	else
		simple_pr_b(stack_a, stack_b, min, pivot);
	quicksort(stack_a, stack_b, pivot + 1, max);
	quicksort_reverse(stack_a, stack_b, min, pivot);
}
