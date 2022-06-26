/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <kmeixner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:09:11 by kmeixner          #+#    #+#             */
/*   Updated: 2022/04/07 00:01:13 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

static int	check_integers(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atolli(argv[i]) < -2147483648 || ft_atolli(argv[i]) > 2147483647)
			return (-1);
		i++;
	}
	return (0);
}

static int	check_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atolli(argv[i]) == ft_atolli(argv[j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	validate_characters(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == 45)
		{
			if (!argv[i][1])
				return (-1);
			j++;
		}
		while (argv[i][j])
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	input_validation(int argc, char **argv)
{
	if (validate_characters(argc, argv) < 0)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	if (check_integers(argc, argv) < 0)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	if (check_duplicates(argc, argv) < 0)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	if (argc <= 2)
		return (-1);
	return (0);
}
