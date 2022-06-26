/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrot_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <kmeixner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 23:05:39 by kmeixner          #+#    #+#             */
/*   Updated: 2022/04/06 18:00:14 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rra(t_list **stack_a)
{
	write(1, "rra\n", 4);
	reverse_rotate(stack_a);
	return (1);
}

int	rrb(t_list **stack_b)
{
	write(1, "rrb\n", 4);
	reverse_rotate(stack_b);
	return (1);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	write(1, "rrr\n", 4);
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	return (1);
}
