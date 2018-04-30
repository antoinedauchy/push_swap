/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 20:15:01 by adauchy           #+#    #+#             */
/*   Updated: 2018/03/08 19:19:52 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		print_stacks_background(t_mlx mlx, t_data *data)
{
	t_coord		pos;
	t_coord		size;

	pos.x = STACK_X;
	pos.y = STACK_B_Y;
	size.x = data->width_block * data->stk->size;
	size.y = HEIGHT_STACK;
	print_square(pos, size, 0xA4A4A4, mlx.img);
	pos.y = STACK_A_Y;
	print_square(pos, size, 0xA4A4A4, mlx.img);
}

void		print_stack(char id, unsigned int *stack, int head, t_data *data)
{
	int		n;
	t_coord	pos;
	t_coord	size;

	n = head;
	size.x = data->width_block;
	while (n < data->stk->size)
	{
		pos.x = STACK_X + n * data->width_block;
		size.y = (HEIGHT_STACK - data->min_size) * stack[n] / data->diff +
					data->min_size;
		pos.y = (id == 'a' ? STACK_A_Y : STACK_B_Y) + HEIGHT_STACK - size.y;
		print_square(pos, size, get_color((long)stack[n], MAX_COLOR, MIN_COLOR,
						(long)data->diff), data->mlx.img);
		n += 1;
	}
}

void		print_stacks(t_data *data)
{
	print_stacks_background(data->mlx, data);
	print_stack('a', (unsigned int*)data->stk->stack_a,
			data->stk->head_a, data);
	print_stack('b', (unsigned int*)data->stk->stack_b,
			data->stk->head_b, data);
}

int			loop_hook(void *ptr)
{
	t_data		*data;
	static int	n = 0;
	static int	print = 0;

	data = (t_data*)ptr;
	if (data->pause)
		return (0);
	if (data->speed >= 0 && print++ < data->speed)
	{
		if (data->instr[n])
			call_instr(data->instr[n++], data->stk);
		return (0);
	}
	if (print >= data->speed)
		print = 0;
	print_stacks(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win,
			data->mlx.img.img, 0, 0);
	return (0);
}
