/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 17:33:44 by adauchy           #+#    #+#             */
/*   Updated: 2018/03/12 20:56:12 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ft_bubble_sort(t_stk *stk)
{
	int		max;

	stk->nb_instr = 0;
	max = get_extrem(stk->stack_a, stk->size, 'B');
	while (!is_sorted(stk->stack_a, stk->size, 'i'))
	{
		if (stk->stack_a[stk->head_a + 1] < stk->stack_a[stk->head_a] &&
			stk->stack_a[stk->head_a] != max)
			call_instr("sa", stk);
		else
			call_instr("ra", stk);
	}
	return (stk->nb_instr);
}
