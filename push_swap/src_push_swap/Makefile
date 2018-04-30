# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adauchy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/21 05:21:10 by adauchy           #+#    #+#              #
#    Updated: 2018/03/15 17:02:53 by adauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=		gcc

RM			=		rm -f

NAME		=		../push_swap

CFLAGS		=		-Wextra -Wall -Werror -g3

LIBFT		=		../libft/libft.a

SRCS		=		../instr/push.c				\
					../instr/rev_rot.c			\
					../instr/rot.c				\
					../instr/swap.c				\
					../instr/call_instr.c		\
					../src_checker/get_stack.c	\
					main.c						\
					sort_the_stack.c			\
					choose_min_sort.c			\
					insertion_sort.c			\
					cheat_sort.c				\
					ft_median_sort.c			\
					tools.c						\
					ft_bubble_sort.c			\
					tools2.c					\
					div_by_two_bubble.c			\

OBJS		=		$(SRCS:.c=.o)

HEADER 		= 		push_swap.h

all			:		$(NAME)

$(NAME)		:		$(OBJS)
					$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF)

%.o 		: 		%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

clean		:
					$(RM) $(OBJS)

fclean		:		clean
					$(RM) $(NAME)

re			:		fclean all

.PHONY		:		all clean fclean re
