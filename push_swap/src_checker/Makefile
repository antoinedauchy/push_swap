# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adauchy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/21 05:21:10 by adauchy           #+#    #+#              #
#    Updated: 2018/03/15 17:02:03 by adauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=		gcc

RM			=		rm -f

NAME		=		../checker

CFLAGS		=		-Wextra -Wall -Werror

LIBFT		=		../libft/libft.a

MNLBX		=		../mnlbx/mnlbx.a

MLX			=		-lmlx -framework OpenGL -framework AppKit -O3

SRCS		=		../instr/push.c				\
					../instr/rev_rot.c			\
					../instr/rot.c				\
					../instr/swap.c				\
					../instr/call_instr.c		\
					main.c						\
					apply_program.c				\
					visu.c						\
					key_hook.c					\
					loop_hook.c					\
					get_stack.c					\

OBJS		=		$(SRCS:.c=.o)

HEADER 		= 		checker.h instr.h

all			:		$(NAME)

$(NAME)		:		$(OBJS)
					$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MNLBX)

%.o 		: 		%.c $(HEADER)
					$(CC) $(CFLAGS) -c $< -o $@

clean		:
					$(RM) $(OBJS)

fclean		:		clean
					$(RM) $(NAME)

re			:		fclean all

.PHONY		:		all clean fclean re
