/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 23:28:25 by adauchy           #+#    #+#             */
/*   Updated: 2018/03/15 18:45:33 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../libft/libft.h"
# include "../instr/instr.h"

# define IN_A			0
# define IN_B			1
# define SORTED			2

typedef struct			s_cheat
{
	int					nb;
	int					status;
}						t_cheat;

# define DEFINED		42
# define NOT_DEFINED	43
# define MAX_SELEC_SORT	15

# define RIGHT			1
# define LEFT			2

typedef struct			s_median
{
	int					stat_start_sort;
	int					start_sort;
	int					stat_end_sort;
	int					end_sort;
	int					*marker;
	int					size_tab;
}						t_median;

int						*get_stack(int ac, char **av, int *size_stack);

int						sort_the_stack(int *stack, int size_stack, int sort,
							int details);

int						choose_min_sort(t_stk *stk);
int						insertion_sort(t_stk *stk);
int						cheat_sort(t_stk *stk);
int						ft_median_sort(t_stk *stk);
int						ft_bubble_sort(t_stk *stk);
int						div_by_two_bubble(t_stk *stk);
int						multi_median(t_stk *stk);

int						get_extrem(int *stack, int size, char which);
int						get_nb_elems(int *stack, int head, int size,
							t_median *median);
int						is_marker(int nb, t_median *median);
int						get_median(int *stack, int size, int *median);
void					median_push(char src, int median, int nb_elems,
							t_stk *stk);
int						add_new_marker(int nb, t_median *median);
int						index_number(int nb, t_cheat *cheat_stack, int size);
void					print_details(int sorts[6], int sort, int size_stack);

#endif
