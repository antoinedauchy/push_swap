/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 23:26:47 by adauchy           #+#    #+#             */
/*   Updated: 2018/03/15 17:37:20 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../instr/instr.h"
# include "../mnlbx/mnlbx.h"
# include <stdlib.h>

# define WIDTH_STACK	1500
# define HEIGHT_STACK	375
# define STACK_X		50
# define STACK_A_Y		475
# define STACK_B_Y		50

# define MIN_COLOR		0x0000FF
# define MAX_COLOR		0xFF0000

typedef struct	s_data
{
	t_stk		*stk;
	char		**instr;
	t_mlx		mlx;
	int			width_block;
	size_t		diff;
	int			min_size;
	int			speed;
	int			pause;
}				t_data;

int				apply_program(int *stack, int *size_stack,
					char **instr, int v_option);
void			visu(t_stk *stk, char **instr);
int				*get_stack(int ac, char **av, int *size_stack);

#endif
