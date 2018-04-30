/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 21:21:00 by adauchy           #+#    #+#             */
/*   Updated: 2018/02/26 21:46:19 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instr.h"

void		ra(t_stk *stk)
{
	int		tmp;
	int		n;

	if (stk->head_a == stk->size)
		return ;
	tmp = stk->stack_a[stk->head_a];
	n = stk->head_a;
	while (n < stk->size - 1)
	{
		stk->stack_a[n] = stk->stack_a[n + 1];
		n += 1;
	}
	stk->stack_a[n] = tmp;
}

void		rb(t_stk *stk)
{
	int		tmp;
	int		n;

	if (stk->head_b == stk->size)
		return ;
	tmp = stk->stack_b[stk->head_b];
	n = stk->head_b;
	while (n < stk->size - 1)
	{
		stk->stack_b[n] = stk->stack_b[n + 1];
		n += 1;
	}
	stk->stack_b[n] = tmp;
}

void		rr(t_stk *stk)
{
	ra(stk);
	rb(stk);
}
