/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrot_ops_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <kmeixner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:57:20 by kmeixner          #+#    #+#             */
/*   Updated: 2022/04/06 16:55:46 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	return (1);
}

int	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	return (1);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	return (1);
}
