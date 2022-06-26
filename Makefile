# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmeixner <kmeixner@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/29 17:00:08 by kmeixner          #+#    #+#              #
#    Updated: 2022/04/09 12:02:42 by kmeixner         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap

BNAME		=	checker

SRCS		=	sources/push_swap.c sources/input_validation.c sources/utils.c \
				sources/lists.c sources/index_list.c sources/sort_five.c \
				sources/pushswap_ops.c sources/rot_ops.c sources/revrot_ops.c \
				sources/operation_utils.c sources/quicksort.c sources/quicksort_utils.c

BSRCS		=	bonus_sources/push_swap_bonus_utils.c bonus_sources/input_validation.c \
				bonus_sources/lists.c	bonus_sources/index_list.c bonus_sources/ft_strjoin.c \
				bonus_sources/ft_split.c bonus_sources/pushswap_ops_bonus.c \
				bonus_sources/rot_ops_bonus.c bonus_sources/revrot_ops_bonus.c \
				bonus_sources/operation_utils.c bonus_sources/push_swap_bonus.c

CC			=	gcc

RM			=	rm

CFLAGS		=	-Wall -Werror -Wextra

all:		$(NAME)

$(NAME):	$(SRCS)
			$(CC) -o $(NAME) $(CFLAGS) $(SRCS)

bonus:		$(BSRCS)
			$(CC) -o $(BNAME) $(CFKAGS) $(BSRCS)

clean:		
			$(RM) -f $(NAME)
			$(RM) -f $(BNAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re bonus