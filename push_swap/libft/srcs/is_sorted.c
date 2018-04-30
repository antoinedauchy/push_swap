/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 23:58:00 by adauchy           #+#    #+#             */
/*   Updated: 2018/03/12 20:48:50 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			is_sorted(int *stack, int size_stack, char order)
{
	int		n;

	n = 0;
	while (n < size_stack - 1)
	{
		if ((order == 'i' && stack[n] > stack[n + 1]) ||
			(order == 'd' && stack[n] < stack[n + 1]))
			return (0);
		n += 1;
	}
	return (1);
}
