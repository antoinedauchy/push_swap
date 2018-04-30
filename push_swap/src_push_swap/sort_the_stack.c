/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_the_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 09:51:54 by adauchy           #+#    #+#             */
/*   Updated: 2018/03/15 18:46:36 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		print_instr(t_stk *stk)
{
	int		n;
	char	**t;

	n = 0;
	t = stk->instrs;
	while (t[n])
	{
		if (t[n + 1] && ((!ft_strcmp("ra", t[n]) &&
						!ft_strcmp("rb", t[n + 1])) ||
						(!ft_strcmp("rb", t[n]) && !ft_strcmp("ra", t[n + 1]))))
		{
			ft_printf("rr\n");
			n += 2;
		}
		else if (t[n + 1] && ((!ft_strcmp("rra", t[n]) &&
						!ft_strcmp("rrb", t[n + 1])) ||
						(!ft_strcmp("rrb", t[n]) &&
						!ft_strcmp("rra", t[n + 1]))))
		{
			ft_printf("rrr\n");
			n += 2;
		}
		else if (ft_printf("%s\n", t[n]))
			n += 1;
	}
}

int			call_sort(int sort, t_stk *stk)
{
	if (!(stk->instrs = (char**)malloc(sizeof(char*))))
		return (-1);
	stk->instrs[0] = NULL;
	stk->print = 1;
	stk->size_instrs = 0;
	if (sort == 1)
		choose_min_sort(stk);
	else if (sort == 2)
		insertion_sort(stk);
	else if (sort == 3)
		cheat_sort(stk);
	else if (sort == 4)
		ft_median_sort(stk);
	else if (sort == 5)
		ft_bubble_sort(stk);
	else
		div_by_two_bubble(stk);
	print_instr(stk);
	free(stk->instrs);
	return (0);
}

int			init_stk(t_stk *stk, int size_stack)
{
	if (!(stk->stack_a = (int*)malloc(size_stack * sizeof(int))))
		return (-1);
	if (!(stk->stack_b = (int*)malloc(size_stack * sizeof(int))))
		return (-1);
	stk->head_a = 0;
	stk->head_b = size_stack;
	stk->size = size_stack;
	return (0);
}

int			test_sorts(t_stk *stk, int *stack, int size_stack, int sorts[6])
{
	stk->print = 0;
	ft_memcpy(stk->stack_a, stack, size_stack * sizeof(int));
	sorts[0] = choose_min_sort(stk);
	ft_memcpy(stk->stack_a, stack, size_stack * sizeof(int));
	sorts[1] = insertion_sort(stk);
	ft_memcpy(stk->stack_a, stack, size_stack * sizeof(int));
	sorts[2] = cheat_sort(stk);
	ft_memcpy(stk->stack_a, stack, size_stack * sizeof(int));
	sorts[3] = ft_median_sort(stk);
	ft_memcpy(stk->stack_a, stack, size_stack * sizeof(int));
	sorts[4] = 2147483647;
	if (stk->size <= 50)
		sorts[4] = ft_bubble_sort(stk);
	ft_memcpy(stk->stack_a, stack, size_stack * sizeof(int));
	sorts[5] = 2147483647;
	if (stk->size <= 50)
		sorts[5] = div_by_two_bubble(stk);
	return (get_pos_number(get_extrem(sorts, 6, 'L'), sorts, 6) + 1);
}

int			sort_the_stack(int *stack, int size_stack, int sort,
				int details)
{
	t_stk	stk;
	int		sorts[6];

	if (init_stk(&stk, size_stack) == -1)
		return (-1);
	if (!sort && (sort = test_sorts(&stk, stack, size_stack, sorts)) == -1)
		return (-1);
	ft_memcpy(stk.stack_a, stack, size_stack * sizeof(int));
	if (!details && call_sort(sort, &stk) == -1)
		return (-1);
	free(stk.stack_a);
	free(stk.stack_b);
	if (details)
		print_details(sorts, sort, size_stack);
	return (0);
}
