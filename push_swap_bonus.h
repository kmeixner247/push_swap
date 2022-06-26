/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmeixner <kmeixner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:22:35 by kmeixner          #+#    #+#             */
/*   Updated: 2022/04/09 12:04:03 by kmeixner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

//				push_swap_bonus_utils.c
int				ft_strcmp(char *s1, char *s2);
int				check_list(t_list **stack_a, t_list **stack_b);
void			free_list(t_list **list);
long long		ft_atolli(char *str);

//				input_validation.c
int				input_validation(int argc, char **argv);

//				lists.c
t_list			*ft_lstnew(int content);
int				ft_lstadd_back(t_list **lst, t_list *new);

//				index_list.c
void			index_list(int listsize, t_list **list);

//				ft_strjoin.c
char			*ft2_strjoin(char *s1, char *s2);
void			*ft_calloc(unsigned int nmemb, unsigned int size);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

//				ft_split.c
char			**ft_split(char const *s, char c);

//				pushswap_ops_bonus.c
int				pa(t_list **stack_a, t_list **stack_b);
int				pb(t_list **stack_a, t_list **stack_b);
int				sa(t_list **stack_a);
int				sb(t_list **stack_b);
int				ss(t_list **stack_a, t_list **stack_b);	

//				rot_ops_bonus.c
int				ra(t_list **stack_a);
int				rb(t_list **stack_b);
int				rr(t_list **stack_a, t_list **stack_b);

//				revrot_ops_bonus.c
int				rra(t_list **stack_a);
int				rrb(t_list **stack_b);
int				rrr(t_list **stack_a, t_list **stack_b);

//				operation_utils.c
void			push(t_list **origin, t_list **target);
void			swap(t_list **list);
void			rotate(t_list **list);
void			reverse_rotate(t_list **list);

#endif