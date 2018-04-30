# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adauchy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/21 05:21:10 by adauchy           #+#    #+#              #
#    Updated: 2018/03/12 20:50:45 by adauchy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all			:
					make -C ./libft
					make -C ./mnlbx
					make -C ./src_checker
					make -C ./src_push_swap

clean		:
					make clean -C ./libft
					make clean -C ./mnlbx
					make clean -C ./src_checker
					make clean -C ./src_push_swap

fclean		:		clean
					make fclean -C ./libft
					make fclean -C ./mnlbx
					make fclean -C ./src_checker
					make fclean -C ./src_push_swap

re			:		fclean all

.PHONY		:		all clean fclean re
