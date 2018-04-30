/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 20:50:54 by adauchy           #+#    #+#             */
/*   Updated: 2018/02/26 21:13:57 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instr.h"

void		sa(t_stk *stk)
{
	int		tmp;

	if (stk->head_a > stk->size - 2)
		return ;
	tmp = stk->stack_a[stk->head_a];
	stk->stack_a[stk->head_a] = stk->stack_a[stk->head_a + 1];
	stk->stack_a[stk->head_a + 1] = tmp;
}

void		sb(t_stk *stk)
{
	int		tmp;

	if (stk->head_b > stk->size - 2)
		return ;
	tmp = stk->stack_b[stk->head_b];
	stk->stack_b[stk->head_b] = stk->stack_b[stk->head_b + 1];
	stk->stack_b[stk->head_b + 1] = tmp;
}

void		ss(t_stk *stk)
{
	sa(stk);
	sb(stk);
}
