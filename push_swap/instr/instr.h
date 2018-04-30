/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 20:48:40 by adauchy           #+#    #+#             */
/*   Updated: 2018/03/15 17:49:09 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTR_H
# define INSTR_H

# include "../libft/libft.h"

typedef struct		s_stk
{
	int				*stack_a;
	int				*stack_b;
	int				head_a;
	int				head_b;
	int				size;
	int				nb_instr;
	int				print;
	char			**instrs;
	int				size_instrs;
}					t_stk;

void				sa(t_stk *stk);
void				sb(t_stk *stk);
void				ss(t_stk *stk);
void				pa(t_stk *stk);
void				pb(t_stk *stk);
void				ra(t_stk *stk);
void				rb(t_stk *stk);
void				rr(t_stk *stk);
void				rra(t_stk *stk);
void				rrb(t_stk *stk);
void				rrr(t_stk *stk);

int					ref_instr(char *instr);
void				call_instr(char *instr, t_stk *stk);

#endif
