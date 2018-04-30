/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 18:43:11 by adauchy           #+#    #+#             */
/*   Updated: 2018/03/15 17:49:13 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			apply_program(int *stack, int *size_stack,
				char **instr, int v_option)
{
	t_stk	stk;
	int		n;

	stk.print = 0;
	stk.stack_a = stack;
	if (!(stk.stack_b = (int*)malloc(*size_stack * sizeof(int))))
		return (-1);
	stk.head_a = 0;
	stk.head_b = *size_stack;
	stk.size = *size_stack;
	if (v_option)
		visu(&stk, instr);
	n = 0;
	while (instr[n])
	{
		call_instr(instr[n], &stk);
		n += 1;
	}
	free(stk.stack_b);
	if (stk.head_a)
		*size_stack = -1;
	return (0);
}
