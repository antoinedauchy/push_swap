/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   div_by_two_bubble.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 20:11:35 by adauchy           #+#    #+#             */
/*   Updated: 2018/03/15 18:45:13 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		bubble_sort(t_stk *stk, int limit, char which)
{
	int			*stack;
	int			head;

	if (which == 'a')
	{
		stack = stk->stack_a;
		head = stk->head_a;
	}
	else
	{
		stack = stk->stack_b;
		head = stk->head_b;
	}
	if ((which == 'a' && is_sorted(&stack[head], stk->size - head, 'i')) ||
		(which == 'b' && is_sorted(&stack[head], stk->size - head, 'd')))
		return (1);
	if ((which == 'a' && stack[head + 1] < stack[head] &&
				stack[head] != limit) ||
		(which == 'b' && stack[head + 1] > stack[head] && stack[head] != limit))
		call_instr((which == 'a' ? "sa" : "sb"), stk);
	else
		call_instr((which == 'a' ? "ra" : "rb"), stk);
	return (0);
}

int				init_stacks(t_stk *stk, int *max_a, int *min_b)
{
	int			median;

	if (get_median(stk->stack_a, stk->size, &median) == -1)
		return (-1);
	median_push('a', median, stk->size, stk);
	*max_a = get_extrem(&stk->stack_a[stk->head_a],
			stk->size - stk->head_a, 'B');
	*min_b = get_extrem(&stk->stack_b[stk->head_b],
			stk->size - stk->head_b, 'L');
	return (0);
}

int				div_by_two_bubble(t_stk *stk)
{
	int			a_sorted;
	int			b_sorted;
	int			max_a;
	int			min_b;

	a_sorted = 0;
	b_sorted = 0;
	stk->nb_instr = 0;
	if (is_sorted(stk->stack_a, stk->size, 'i'))
		return (0);
	if (init_stacks(stk, &max_a, &min_b) == -1)
		return (-1);
	while (!a_sorted || !b_sorted)
	{
		if (!a_sorted)
			a_sorted = bubble_sort(stk, max_a, 'a');
		if (!b_sorted)
			b_sorted = bubble_sort(stk, min_b, 'b');
	}
	while (stk->head_b != stk->size)
		call_instr("pa", stk);
	return (stk->nb_instr);
}
