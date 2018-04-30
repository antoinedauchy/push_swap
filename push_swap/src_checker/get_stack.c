/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 07:50:27 by adauchy           #+#    #+#             */
/*   Updated: 2018/03/15 17:17:10 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		write_ends(char **tab)
{
	int		n;
	int		m;

	n = 0;
	while (tab[n])
	{
		m = 0;
		while (!is_in_str(tab[n][m], "\t ") && tab[n][m])
			m += 1;
		tab[n][m] = '\0';
		n += 1;
	}
}

char		**get_tab(char *str, int **stack, int *size_stack)
{
	int		nb_nb;
	char	**t;
	int		n;
	int		m;

	nb_nb = get_nb_str(str, "\t ");
	if (!nb_nb || !(t = (char**)malloc((nb_nb + 1) * sizeof(char*))) ||
		!(*stack = ft_realloc_simple_tab(*stack, size_stack, nb_nb)))
		return (NULL);
	n = 0;
	while (is_in_str(str[n], "\t "))
		n += 1;
	m = 0;
	while (str[n])
	{
		t[m] = &str[n];
		while (!is_in_str(str[n], "\t ") && str[n])
			n += 1;
		while (is_in_str(str[n], "\t "))
			n += 1;
		m += 1;
	}
	t[m] = NULL;
	write_ends(t);
	return (t);
}

int			get_args(char **tab, int *stack, int *i)
{
	int		m;

	m = 0;
	while (tab[m])
	{
		if (!nb_is_valid(tab[m], &stack[(*i)++]))
		{
			free(stack);
			free(tab);
			return (-1);
		}
		m += 1;
	}
	free(tab);
	return (0);
}

static int	check_duplicate(int *stack, int size_stack)
{
	int		n;
	int		m;

	n = 0;
	while (n < size_stack - 1)
	{
		m = n + 1;
		while (m < size_stack)
		{
			if (stack[n] == stack[m])
				return (-1);
			m += 1;
		}
		n += 1;
	}
	return (0);
}

int			*get_stack(int ac, char **av, int *size_stack)
{
	int		i;
	int		n;
	int		*stack;
	char	**tab;

	stack = NULL;
	n = 0;
	i = 0;
	*size_stack = 0;
	while (n < ac)
	{
		if (!(tab = get_tab(av[n], &stack, size_stack)))
			return (NULL);
		if (get_args(tab, stack, &i) == -1)
			return (NULL);
		n += 1;
	}
	if (check_duplicate(stack, *size_stack) == -1)
	{
		free(stack);
		return (NULL);
	}
	return (stack);
}
