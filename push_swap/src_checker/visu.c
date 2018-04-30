/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 19:38:03 by adauchy           #+#    #+#             */
/*   Updated: 2018/03/01 18:56:27 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		get_min_value(int *stack, int size)
{
	int			min;
	int			n;

	min = *stack;
	n = 0;
	while (n < size)
	{
		if (stack[n] < min)
			min = stack[n];
		n += 1;
	}
	return (min);
}

static int		get_diff(unsigned int *stack, int size)
{
	int				n;
	size_t			max;

	max = *stack;
	n = 0;
	while (n < size)
	{
		if (stack[n] > max)
			max = stack[n];
		n += 1;
	}
	return (max);
}

static void		get_min_to_zero(unsigned int *stack, int size, int min)
{
	int			n;

	n = 0;
	while (n < size)
	{
		stack[n] -= min;
		n += 1;
	}
}

static void		init_print_vars(t_data *data)
{
	int			min;

	data->pause = 0;
	data->speed = 1;
	data->width_block = WIDTH_STACK / data->stk->size;
	data->min_size = HEIGHT_STACK / 20;
	min = get_min_value(data->stk->stack_a, data->stk->size);
	if (min)
		get_min_to_zero((unsigned int*)data->stk->stack_a,
				data->stk->size, min);
	data->diff = get_diff((unsigned int*)data->stk->stack_a, data->stk->size);
}

void			visu(t_stk *stk, char **instr)
{
	t_mlx	mlx;
	t_data	data;

	data.stk = stk;
	data.instr = instr;
	if (init_mlx(&mlx, 1600, 900, "PUSH_SWAP ADAUCHY") == -1)
		return ;
	data.mlx = mlx;
	init_print_vars(&data);
	mlx_loop_hook(mlx.mlx, loop_hook, &data);
	mlx_key_hook(mlx.win, key_hook, &data);
	mlx_loop(mlx.mlx);
}
