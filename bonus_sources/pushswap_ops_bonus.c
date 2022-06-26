/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_ops_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <kmeixner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:53:27 by kmeixner          #+#    #+#             */
/*   Updated: 2022/04/09 12:04:37 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (!(*stack_b))
		return (0);
	push(stack_b, stack_a);
	return (1);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (!(*stack_a))
		return (0);
	push(stack_a, stack_b);
	return (1);
}

int	sa(t_list **stack_a)
{
	swap(stack_a);
	return (1);
}

int	sb(t_list **stack_b)
{
	swap(stack_b);
	return (1);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	return (1);
}
