/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_median_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 21:34:01 by adauchy           #+#    #+#             */
/*   Updated: 2018/03/13 21:50:38 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		push_a_to_b(t_stk *stk, t_median *median)
{
	int		median_elem;
	int		nb_elems;
	int		count;

	nb_elems = get_nb_elems(stk->stack_a, stk->head_a, stk->size, median);
	if (nb_elems <= MAX_SELEC_SORT)
		median_elem = get_extrem(&stk->stack_a[stk->head_a], nb_elems, 'B');
	else if (get_median(&stk->stack_a[stk->head_a], nb_elems,
			&median_elem) == -1)
		return (-1);
	count = 0;
	median_push('a', median_elem, nb_elems, stk);
	while (median->stat_end_sort == DEFINED &&
			stk->stack_a[stk->size - 1] != median->end_sort)
		call_instr("rra", stk);
	return (0);
}

static void		send_min_to_a(t_stk *stk)
{
	int			min;
	int			pos_min;
	int			dir;
	static int	nb_to_ra = 0;

	min = get_extrem(&stk->stack_b[stk->head_b], stk->size - stk->head_b, 'L');
	pos_min = stk->head_b;
	while (stk->stack_b[pos_min] != min)
		pos_min += 1;
	dir = RIGHT;
	if (pos_min - stk->head_b < stk->size - 1 - pos_min)
		dir = LEFT;
	while (stk->stack_b[stk->head_b] != min)
	{
		if (!nb_to_ra || (nb_to_ra && dir == RIGHT))
			call_instr((dir == RIGHT ? "rrb" : "rb"), stk);
		else if (dir == LEFT && !(nb_to_ra = 0))
			call_instr("rr", stk);
	}
	if (nb_to_ra && !(nb_to_ra = 0))
		call_instr("ra", stk);
	call_instr("pa", stk);
	nb_to_ra = 1;
	if (stk->head_b == stk->size && !(nb_to_ra = 0))
		call_instr("ra", stk);
}

static int		push_b_to_a(t_stk *stk, t_median *median)
{
	int		median_elem;

	while (stk->head_b != stk->size)
	{
		if (stk->size - stk->head_b > MAX_SELEC_SORT)
		{
			if (add_new_marker(stk->stack_a[stk->head_a], median) == -1 ||
				get_median(&stk->stack_b[stk->head_b], stk->size - stk->head_b,
				&median_elem) == -1)
				return (-1);
			median_push('b', median_elem, stk->size - stk->head_b, stk);
		}
		else
		{
			if (median->stat_start_sort == NOT_DEFINED
					&& (median->stat_start_sort = DEFINED))
				median->start_sort = get_extrem(&stk->stack_b[stk->head_b],
						stk->size - stk->head_b, 'L');
			while (stk->head_b != stk->size)
				send_min_to_a(stk);
			median->stat_end_sort = DEFINED;
			median->end_sort = stk->stack_a[stk->size - 1];
		}
	}
	return (0);
}

int				ft_median_sort(t_stk *stk)
{
	int			max_all;
	t_median	median;

	stk->nb_instr = 0;
	median.stat_start_sort = NOT_DEFINED;
	median.stat_end_sort = NOT_DEFINED;
	median.marker = NULL;
	median.size_tab = 0;
	max_all = get_extrem(stk->stack_a, stk->size, 'B');
	while (median.stat_end_sort == NOT_DEFINED || median.end_sort != max_all)
	{
		if (!stk->head_a && is_sorted(stk->stack_a, stk->size, 'i'))
			break ;
		if (push_a_to_b(stk, &median) == -1)
			return (-1);
		if (push_b_to_a(stk, &median) == -1)
			return (-1);
	}
	if (median.marker)
		free(median.marker);
	return (stk->nb_instr);
}
