/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 21:42:05 by adauchy           #+#    #+#             */
/*   Updated: 2018/02/26 21:51:57 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instr.h"

void		rra(t_stk *stk)
{
	int		tmp;
	int		n;

	if (stk->head_a == stk->size)
		return ;
	tmp = stk->stack_a[stk->size - 1];
	n = stk->size - 1;
	while (n > stk->head_a)
	{
		stk->stack_a[n] = stk->stack_a[n - 1];
		n -= 1;
	}
	stk->stack_a[n] = tmp;
}

void		rrb(t_stk *stk)
{
	int		tmp;
	int		n;

	if (stk->head_b == stk->size)
		return ;
	tmp = stk->stack_b[stk->size - 1];
	n = stk->size - 1;
	while (n > stk->head_b)
	{
		stk->stack_b[n] = stk->stack_b[n - 1];
		n -= 1;
	}
	stk->stack_b[n] = tmp;
}

void		rrr(t_stk *stk)
{
	rra(stk);
	rrb(stk);
}
