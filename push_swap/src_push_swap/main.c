/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 23:27:35 by adauchy           #+#    #+#             */
/*   Updated: 2018/03/15 18:18:39 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				get_choosen_sort(char *sort, int *details)
{
	*details = 0;
	if (!ft_strcmp("choose_min", sort))
		return (1);
	if (!ft_strcmp("insertion", sort))
		return (2);
	if (!ft_strcmp("cheat", sort))
		return (3);
	if (!ft_strcmp("median", sort))
		return (4);
	if (!ft_strcmp("bubble", sort))
		return (5);
	if (!ft_strcmp("double_bubble", sort))
		return (6);
	if (!ft_strcmp("-details", sort))
		*details = 1;
	return (0);
}

int				main(int ac, char **av)
{
	int		*stack;
	int		size_stack;
	int		sort;
	int		details;

	if (ac == 1)
		return (0);
	if ((sort = get_choosen_sort(av[1], &details)) && ac == 2)
		return (0);
	if (!(stack = get_stack(ac - (sort || details ? 2 : 1),
				&av[(sort || details ? 2 : 1)], &size_stack)))
		return (ft_printf("Error\n"));
	if (sort_the_stack(stack, size_stack, sort, details) == -1)
		return (-1);
	free(stack);
	return (0);
}
