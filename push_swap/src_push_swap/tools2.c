/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 20:40:37 by adauchy           #+#    #+#             */
/*   Updated: 2018/03/15 18:28:59 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			get_extrem(int *stack, int size, char which)
{
	int		extrem;
	int		count;

	count = 0;
	extrem = stack[count];
	while (count < size)
	{
		if (which == 'B' && stack[count] > extrem)
			extrem = stack[count];
		else if (which == 'L' && stack[count] < extrem)
			extrem = stack[count];
		count += 1;
	}
	return (extrem);
}

int			index_number(int nb, t_cheat *cheat_stack, int size)
{
	int			n;

	n = 0;
	while (n < size)
	{
		if (cheat_stack[n].nb == nb)
			break ;
		n += 1;
	}
	return (n);
}

void		print_details(int sorts[6], int sort, int size_stack)
{
	ft_printf("%schoose_min    ==> %d instructions%s\n",
			(sorts[0] == sorts[sort - 1] ? GREEN : ""), sorts[0], RESET);
	ft_printf("%sinsertion     ==> %d instructions%s\n",
			(sorts[1] == sorts[sort - 1] ? GREEN : ""), sorts[1], RESET);
	ft_printf("%scheat         ==> %d instructions%s\n",
			(sorts[2] == sorts[sort - 1] ? GREEN : ""), sorts[2], RESET);
	ft_printf("%smedian        ==> %d instructions%s\n",
			(sorts[3] == sorts[sort - 1] ? GREEN : ""), sorts[3], RESET);
	if (size_stack <= 50)
	{
		ft_printf("%sbubble        ==> %d instructions%s\n",
				(sorts[4] == sorts[sort - 1] ? GREEN : ""), sorts[4], RESET);
		ft_printf("%sdouble_bubble ==> %d instructions%s\n",
				(sorts[5] == sorts[sort - 1] ? GREEN : ""), sorts[5], RESET);
	}
	else
	{
		ft_printf("bubble        ==> Too many numbers\n");
		ft_printf("double_bubble ==> Too many numbers\n");
	}
}
