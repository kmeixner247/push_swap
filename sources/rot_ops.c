/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <kmeixner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:48:07 by kmeixner          #+#    #+#             */
/*   Updated: 2022/04/06 18:00:18 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ra(t_list **stack_a)
{
	write(1, "ra\n", 3);
	rotate(stack_a);
	return (1);
}

int	rb(t_list **stack_b)
{
	write(1, "rb\n", 3);
	rotate(stack_b);
	return (1);
}

int	rr(t_list **stack_a, t_list **stack_b)
{
	write(1, "rr\n", 3);
	rotate(stack_a);
	rotate(stack_b);
	return (1);
}
