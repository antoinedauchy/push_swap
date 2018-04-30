/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 21:53:37 by adauchy           #+#    #+#             */
/*   Updated: 2018/03/15 19:27:08 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instr.h"

int			ref_instr(char *instr)
{
	int				n;
	static char		t[11][4] = {"sa", "sb", "ss", "pa",
							"pb", "ra", "rb", "rr",
							"rra", "rrb", "rrr"};

	n = 0;
	while (n < 11)
	{
		if (!ft_strcmp(instr, t[n]))
			return (n);
		n += 1;
	}
	return (-1);
}

void		call_instr(char *instr, t_stk *stk)
{
	static void		(*tab_instr[11])(t_stk *stk) = {&sa, &sb, &ss,
		&pa, &pb, &ra, &rb, &rr, &rra, &rrb, &rrr};

	tab_instr[ref_instr(instr)](stk);
	if (stk->print)
	{
		if (stk->nb_instr == stk->size_instrs)
		{
			if (!(stk->instrs = ft_realloc_double_tab(stk->instrs,
					stk->nb_instr, 1000)))
				return ;
			stk->size_instrs += 1000;
		}
		stk->instrs[stk->nb_instr] = instr;
	}
	stk->nb_instr += 1;
}
