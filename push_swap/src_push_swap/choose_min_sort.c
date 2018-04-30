/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_min_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:01:01 by adauchy           #+#    #+#             */
/*   Updated: 2018/03/12 20:54:56 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			choose_min_sort(t_stk *stk)
{
	int		n;
	int		pos_min;

	if (is_sorted(stk->stack_a, stk->size, 'i'))
		return (0);
	stk->nb_instr = 0;
	while (stk->head_a != stk->size)
	{
		n = stk->head_a;
		pos_min = stk->head_a;
		while (n < stk->size)
		{
			if (stk->stack_a[n] < stk->stack_a[pos_min])
				pos_min = n;
			n += 1;
		}
		n = -1;
		while (++n < pos_min - stk->head_a)
			call_instr("ra", stk);
		call_instr("pb", stk);
	}
	while (stk->head_b != stk->size)
		call_instr("pa", stk);
	return (stk->nb_instr);
}
