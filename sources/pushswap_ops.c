/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_ops.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <kmeixner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:31:36 by kmeixner          #+#    #+#             */
/*   Updated: 2022/04/06 17:59:59 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pa(t_list **stack_a, t_list **stack_b)
{
	write(1, "pa\n", 3);
	if (!(*stack_b))
		return (0);
	push(stack_b, stack_a);
	return (1);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	write(1, "pb\n", 3);
	if (!(*stack_a))
		return (0);
	push(stack_a, stack_b);
	return (1);
}

int	sa(t_list **stack_a)
{
	write(1, "sa\n", 3);
	swap(stack_a);
	return (1);
}

int	sb(t_list **stack_b)
{
	write(1, "sb\n", 3);
	swap(stack_b);
	return (1);
}
