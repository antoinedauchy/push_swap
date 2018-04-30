/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheat_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:09:30 by adauchy           #+#    #+#             */
/*   Updated: 2018/03/12 20:55:40 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cheat			*get_cheat_stack(t_stk *stk)
{
	t_cheat		*cheat_stack;
	int			*tmp;
	int			n;

	if (!(cheat_stack = (t_cheat*)malloc(stk->size * sizeof(t_cheat))))
		return (NULL);
	if (!(tmp = (int*)malloc(stk->size * sizeof(int))))
		return (NULL);
	ft_memcpy(tmp, stk->stack_a, (stk->size * sizeof(int)));
	ft_sort_integer_table(tmp, stk->size);
	n = 0;
	while (n < stk->size)
	{
		cheat_stack[n].nb = tmp[n];
		cheat_stack[n].status = IN_A;
		n += 1;
	}
	free(tmp);
	return (cheat_stack);
}

void			find_the_place(t_stk *stk)
{
	int		nb_rot;

	nb_rot = 0;
	while (stk->stack_a[stk->head_a] < stk->stack_b[stk->size - 1])
	{
		call_instr("rrb", stk);
		nb_rot += 1;
	}
	call_instr("pb", stk);
	while (nb_rot >= 0)
	{
		call_instr("rb", stk);
		nb_rot -= 1;
	}
}

void			push_sorting_in_b(t_stk *stk, t_cheat *cheat_stack)
{
	cheat_stack[index_number(stk->stack_a[stk->head_a],
			cheat_stack, stk->size)].status = IN_B;
	if (stk->head_b == stk->size || (stk->head_b == stk->size - 1 &&
			stk->stack_a[stk->head_a] < stk->stack_b[stk->head_b]))
		call_instr("pb", stk);
	else if (stk->head_b == stk->size - 1)
	{
		call_instr("pb", stk);
		call_instr("rb", stk);
	}
	else if (stk->stack_a[stk->head_a] < stk->stack_b[stk->head_b])
		call_instr("pb", stk);
	else if (stk->stack_a[stk->head_a] > stk->stack_b[stk->size - 1])
	{
		call_instr("pb", stk);
		call_instr("rb", stk);
	}
	else
		find_the_place(stk);
}

void			place_elem(t_stk *stk, t_cheat *cheat_stack, int *next_to_sort)
{
	if (stk->stack_a[stk->head_a] == cheat_stack[*next_to_sort].nb)
	{
		call_instr("ra", stk);
		cheat_stack[*next_to_sort].status = SORTED;
		*next_to_sort += 1;
	}
	else if (cheat_stack[*next_to_sort].status == IN_B)
	{
		call_instr("pa", stk);
		call_instr("ra", stk);
		cheat_stack[*next_to_sort].status = SORTED;
		*next_to_sort += 1;
	}
	else
		push_sorting_in_b(stk, cheat_stack);
}

int				cheat_sort(t_stk *stk)
{
	t_cheat		*cheat_stack;
	int			next_to_sort;

	if (is_sorted(stk->stack_a, stk->size, 'i'))
		return (0);
	stk->nb_instr = 0;
	if (!(cheat_stack = get_cheat_stack(stk)))
		return (-1);
	next_to_sort = 0;
	while (cheat_stack[stk->size - 1].status != SORTED)
		place_elem(stk, cheat_stack, &next_to_sort);
	free(cheat_stack);
	return (stk->nb_instr);
}
