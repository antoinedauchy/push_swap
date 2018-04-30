/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 21:14:26 by adauchy           #+#    #+#             */
/*   Updated: 2018/02/26 21:45:22 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "instr.h"

void		pa(t_stk *stk)
{
	if (stk->head_b == stk->size)
		return ;
	stk->stack_a[stk->head_a - 1] = stk->stack_b[stk->head_b];
	stk->head_a -= 1;
	stk->head_b += 1;
}

void		pb(t_stk *stk)
{
	if (stk->head_a == stk->size)
		return ;
	stk->stack_b[stk->head_b - 1] = stk->stack_a[stk->head_a];
	stk->head_a += 1;
	stk->head_b -= 1;
}
