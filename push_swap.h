/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <kmeixner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:10:59 by kmeixner          #+#    #+#             */
/*   Updated: 2022/04/08 21:57:01 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

//			input_validation.c
int			input_validation(int argc, char **argv);

//			utils.c
long long	ft_atolli(char *str);
int			find_next(t_list **list, int min, int max);
void		adjust_lists(t_list **stack_a, t_list **stack_b, int ac, int bc);

//			lists.c
t_list		*ft_lstnew(int content);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			listsize(t_list **list);
int			listmax(t_list **list);
int			listmin(t_list **list);

//			index_list.c
void		index_list(int listsize, t_list **list);

//			sort_five.c
void		sort_five(t_list **stack_a, t_list **stack_b, int n);

//			pushswap_ops.c
int			pa(t_list **stack_a, t_list **stack_b);
int			pb(t_list **stack_a, t_list **stack_b);
int			sa(t_list **stack_a);
int			sb(t_list **stack_b);

//			rot_ops.c
int			ra(t_list **stack_a);
int			rb(t_list **stack_b);
int			rr(t_list **stack_a, t_list **stack_b);

//			revrot_ops.c
int			rra(t_list **stack_a);
int			rrb(t_list **stack_b);
int			rrr(t_list **stack_a, t_list **stack_b);

//			operation_utils.c
void		push(t_list **origin, t_list **target);
void		swap(t_list **list);
void		rotate(t_list **list);
void		reverse_rotate(t_list **list);
void		smart_rotate(t_list **stack_a, int n);

//			quicksort.c
void		quicksort(t_list **stack_a, t_list **stack_b, int min, int max);

//			quicksort_utils.c
void		pushrange_a(t_list **stack_a, t_list **stack_b, int min, int max);
void		pushrange_b(t_list **stack_a, t_list **stack_b, int min, int max);
void		simple_pr_a(t_list **stack_a, t_list **stack_b, int min, int max);
void		simple_pr_b(t_list **stack_a, t_list **stack_b, int min, int max);

//			sort_five.c
void		sort_five(t_list **stack_a, t_list **stack_b, int n);
#endif