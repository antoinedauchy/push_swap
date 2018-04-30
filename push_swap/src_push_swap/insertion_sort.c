/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 15:45:29 by adauchy           #+#    #+#             */
/*   Updated: 2018/03/12 20:55:21 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	this_is_the_place(t_stk *stk)
{
	if (stk->size - stk->head_b < 2 ||
		(stk->stack_a[stk->head_a] > stk->stack_b[stk->head_b] &&
		stk->stack_a[stk->head_a] < stk->stack_b[stk->size - 1]) ||
		(stk->stack_a[stk->head_a] > stk->stack_b[stk->head_b] &&
		stk->stack_b[stk->head_b] > stk->stack_b[stk->size - 1]) ||
		(stk->stack_a[stk->head_a] < stk->stack_b[stk->head_b] &&
		stk->stack_a[stk->head_a] < stk->stack_b[stk->size - 1] &&
		stk->stack_b[stk->head_b] > stk->stack_b[stk->size - 1]))
		return (1);
	return (0);
}

int			insertion_sort(t_stk *stk)
{
	int		max;

	if (is_sorted(stk->stack_a, stk->size, 'i'))
		return (0);
	stk->nb_instr = 0;
	max = stk->stack_a[0];
	while (stk->head_a != stk->size)
	{
		while (42)
		{
			if (this_is_the_place(stk))
				break ;
			call_instr("rrb", stk);
		}
		if (stk->stack_a[stk->head_a] > max)
			max = stk->stack_a[stk->head_a];
		call_instr("pb", stk);
	}
	while (stk->stack_b[stk->head_b] != max)
		call_instr("rb", stk);
	while (stk->head_b != stk->size)
		call_instr("pa", stk);
	return (stk->nb_instr);
}
