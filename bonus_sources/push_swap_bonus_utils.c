/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:08:05 by kmeixner          #+#    #+#             */
/*   Updated: 2022/04/07 11:33:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while ((unsigned char)s1[i] != '\0')
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	if ((unsigned char)s1[i] != (unsigned char)s2[i])
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}

int	check_list(t_list **list, t_list **stack_b)
{
	t_list	*tmp;

	if (*stack_b)
	{
		write(1, "KO\n", 3);
		return (0);
	}
	tmp = *list;
	while (tmp && tmp->next)
	{
		if (tmp->next->content != tmp->content + 1)
		{
			write(1, "KO\n", 3);
			return (0);
		}
		tmp = tmp->next;
	}
	write(1, "OK\n", 3);
	return (1);
}

void	free_list(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (*list)
	{
		*list = (*list)->next;
		free(tmp);
		tmp = *list;
	}
}

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
