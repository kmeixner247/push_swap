/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <kmeixner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:24:26 by kmeixner          #+#    #+#             */
/*   Updated: 2022/04/09 12:04:52 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*create_list(int argc, char *argv[])
{
	int		i;
	t_list	*stack_a;

	stack_a = ft_lstnew(ft_atolli(argv[1]));
	i = 2;
	while (i < argc)
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atolli(argv[i])));
		i++;
	}
	return (stack_a);
}

void	sort(t_list **stack_a, t_list **stack_b, int argc)
{
	if (argc <= 6)
		sort_five(stack_a, stack_b, argc - 1);
	else
		quicksort(stack_a, stack_b, 1, argc - 1);
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

int	check_list(t_list **list)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp && tmp->next)
	{
		if (tmp->next->content != tmp->content + 1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		i;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	i = input_validation(argc, argv);
	if (i < 0)
		return (0);
	stack_a = create_list(argc, argv);
	index_list(argc - 1, &stack_a);
	if (!check_list(&stack_a))
		sort(&stack_a, &stack_b, argc);
	free_list(&stack_a);
	free(stack_a);
	if (stack_b)
	{
		free_list(&stack_b);
		free(stack_b);
	}
	return (0);
}
