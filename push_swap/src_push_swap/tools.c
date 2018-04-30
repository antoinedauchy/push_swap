/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 23:02:55 by adauchy           #+#    #+#             */
/*   Updated: 2018/03/12 21:33:47 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			add_new_marker(int nb, t_median *median)
{
	if (!(median->marker = ft_realloc_simple_tab(median->marker,
		&median->size_tab, 1)))
		return (-1);
	median->marker[median->size_tab - 1] = nb;
	return (0);
}

int			get_median(int *stack, int size, int *median)
{
	int		*sorted;

	if (!(sorted = (int*)malloc(size * sizeof(int))))
		return (-1);
	ft_memcpy(sorted, stack, size * sizeof(int));
	ft_sort_integer_table(sorted, size);
	*median = sorted[size / 2];
	free(sorted);
	return (0);
}

int			is_marker(int nb, t_median *median)
{
	int		n;

	n = 0;
	while (n < median->size_tab)
	{
		if (nb == median->marker[n])
			return (1);
		n += 1;
	}
	return (0);
}

int			get_nb_elems(int *stack, int head, int size, t_median *median)
{
	int		count;

	count = 0;
	while (count + head < size)
	{
		if (count && (is_marker(stack[count + head], median) ||
				(median->stat_start_sort == DEFINED &&
				stack[count + head] == median->start_sort)))
			break ;
		count += 1;
	}
	return (count);
}

void		median_push(char src, int median, int nb_elems, t_stk *stk)
{
	int		count;

	count = 0;
	while (count < nb_elems)
	{
		if ((src == 'a' && stk->stack_a[stk->head_a] <= median) ||
			(src == 'b' && stk->stack_b[stk->head_b] > median))
			call_instr((src == 'a' ? "pb" : "pa"), stk);
		else
			call_instr((src == 'a' ? "ra" : "rb"), stk);
		count += 1;
	}
}
