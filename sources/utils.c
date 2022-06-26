/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <kmeixner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:10:36 by kmeixner          #+#    #+#             */
/*   Updated: 2022/04/06 18:03:07 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long long	ft_atolli(char *str)
{
	int			i;
	int			sign;
	int			nbrlen;
	long long	nbr;
	int			mag;

	i = 0;
	sign = 1;
	nbrlen = 0;
	mag = 1;
	nbr = 0;
	if (str[i] == 45)
	{
		sign = -1;
		i++;
	}
	while (str[i + nbrlen] >= 48 && str[i + nbrlen] <= 57)
		nbrlen++;
	while (nbrlen > 0)
	{
		nbr += (str[nbrlen + i - 1] - 48) * mag;
		mag *= 10;
		nbrlen--;
	}
	return (sign * nbr);
}

int	find_next(t_list **list, int min, int max)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp && (tmp->content < min || tmp->content > max))
		tmp = tmp->next;
	if (!tmp)
		return (0);
	else
		return (tmp->content);
}

void	adjust_lists(t_list **stack_a, t_list **stack_b, int ac, int bc)
{
	while (ac > 0 && bc > 0)
	{
		ac -= rrr(stack_a, stack_b);
		bc--;
	}
	while (ac > 0)
		ac -= rra(stack_a);
	while (bc > 0)
		bc -= rrb(stack_b);
}
