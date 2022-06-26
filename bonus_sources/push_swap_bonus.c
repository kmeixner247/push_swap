/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <kmeixner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:59:49 by kmeixner          #+#    #+#             */
/*   Updated: 2022/04/09 11:47:23 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

char	**read_inputs(t_list **stack_a, int argc, char **argv)
{
	int		i;
	char	*instructions;
	char	*buf;
	char	**instructionarr;

	i = 2;
	while (i < argc)
		i += ft_lstadd_back(stack_a, ft_lstnew(ft_atolli(argv[i])));
	index_list(argc - 1, stack_a);
	instructions = ft_calloc(sizeof(char), 2);
	buf = ft_calloc(sizeof(char), 2);
	i = read(0, buf, 1);
	while (i)
	{
		if (instructions[0])
			instructions = ft2_strjoin(instructions, buf);
		else
			ft_strlcpy(instructions, buf, 2);
		i = read(0, buf, 1);
	}
	instructionarr = ft_split(instructions, '\n');
	free(buf);
	free(instructions);
	return (instructionarr);
}

int	execute_instruction(t_list **stack_a, t_list **stack_b, char *line)
{
	if (!ft_strcmp(line, "sa"))
		sa(stack_a);
	else if (!ft_strcmp(line, "sb"))
		sb(stack_b);
	else if (!ft_strcmp(line, "ss"))
		ss(stack_a, stack_b);
	else if (!ft_strcmp(line, "pa"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp(line, "pb"))
		pb(stack_a, stack_b);
	else if (!ft_strcmp(line, "ra"))
		ra(stack_a);
	else if (!ft_strcmp(line, "rb"))
		rb(stack_b);
	else if (!ft_strcmp(line, "rr"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(line, "rra"))
		rra(stack_a);
	else if (!ft_strcmp(line, "rrb"))
		rrb(stack_b);
	else if (!ft_strcmp(line, "rrr"))
		rrr(stack_a, stack_b);
	else
		return (0);
	return (1);
}

void	sort_and_check(t_list **stack_a, t_list **stack_b, char **arr)
{	
	int	i;

	i = 0;
	while (arr[i])
	{
		if (!execute_instruction(stack_a, stack_b, arr[i]))
		{
			write(1, "Error\n", 6);
			return ;
		}
		i++;
	}
	check_list(stack_a, stack_b);
}

void	free_contents(t_list **stack_a, t_list **stack_b, char **instructionarr)
{
	int	i;

	if (stack_a)
		free_list(stack_a);
	if (stack_b)
		free_list(stack_b);
	i = 0;
	while (instructionarr[i])
	{
		free(instructionarr[i]);
		i++;
	}	
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**instructionarr;

	stack_b = NULL;
	if (input_validation(argc, argv) < 0)
		return (0);
	stack_a = ft_lstnew(ft_atolli(argv[1]));
	instructionarr = read_inputs(&stack_a, argc, argv);
	sort_and_check(&stack_a, &stack_b, instructionarr);
	free_contents(&stack_a, &stack_b, instructionarr);
	free(instructionarr);
	if (stack_a)
		free(stack_a);
	if (stack_b)
		free(stack_b);
	return (0);
}
