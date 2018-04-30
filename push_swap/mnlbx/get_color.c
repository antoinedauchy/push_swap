/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:33:00 by adauchy           #+#    #+#             */
/*   Updated: 2018/02/28 09:14:03 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mnlbx.h"

int			get_color(long nb, long start, long end, long diff)
{
	long	r;
	long	g;
	long	b;

	r = end / 0x10000 + ((start / 0x10000 - end / 0x10000) * nb) / diff;
	g = end / 0x100 % 0x100 + ((start / 0x100 % 0x100 - end / 0x100 % 0x100) *
							nb) / diff;
	b = end % 0x100 + ((start % 0x100 - end % 0x100) * nb) / diff;
	return (r * 0x10000 + g * 0x100 + b);
}
