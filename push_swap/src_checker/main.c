/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 23:26:08 by adauchy           #+#    #+#             */
/*   Updated: 2018/03/15 20:07:54 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		*free_all(char *instr, char **ret, int *stack)
{
	free(instr);
	ft_free_2d_tab((void**)ret, 1);
	free(stack);
	return (NULL);
}

char		**get_instr(int *stack)
{
	char	*instr;
	char	**ret;
	int		ret_gnl;
	int		n;
	int		size_tab;

	if (!(ret = (char**)malloc(sizeof(char*))))
		return (NULL);
	ret[0] = NULL;
	n = 0;
	size_tab = 0;
	while ((ret_gnl = get_next_line(0, &instr)) == 1)
	{
		if (ref_instr(instr) == -1)
			return (free_all(instr, ret, stack));
		if (n == size_tab && (size_tab += 1000))
			if (!(ret = ft_realloc_double_tab(ret, n, 1000)))
				return (NULL);
		ret[n] = instr;
		n += 1;
	}
	if (ret_gnl == -1)
		return (NULL);
	return (ret);
}

int			main(int ac, char **av)
{
	int		*stack;
	int		size_stack;
	char	**instr;
	int		v_option;

	v_option = 0;
	if (ac > 2 && !ft_strcmp(av[1], "-v") && (v_option = 1) && (ac -= 2))
		av = &av[2];
	else if (ac >= 2 && ft_strcmp(av[1], "-v") && (ac -= 1))
		av = &av[1];
	else
		return (ft_printf("Usage : ./checker [-v] [number ...]\n"));
	if (!(stack = get_stack(ac, av, &size_stack)))
		return (ft_printf("Error\n"));
	if (!(instr = get_instr(stack)))
		return (ft_printf("Error\n"));
	if (instr[0] && apply_program(stack, &size_stack, instr, v_option) == -1)
		return (-1);
	if (size_stack != -1 && is_sorted(stack, size_stack, 'i'))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_free_2d_tab((void**)instr, 1);
	free(stack);
	return (0);
}
