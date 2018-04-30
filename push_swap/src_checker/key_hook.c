/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 20:13:26 by adauchy           #+#    #+#             */
/*   Updated: 2018/03/15 17:43:17 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			key_hook(int keycode, void *ptr)
{
	t_data	*data;

	data = (t_data*)ptr;
	if (keycode == ECHAP)
		exit(0);
	if (keycode == UP)
		data->speed += 1;
	else if (keycode == DOWN && data->speed != 1)
		data->speed -= 1;
	ft_printf("keycode ==> %d\n", keycode);
	if (keycode == SPACE)
	{
		if (data->pause)
			data->pause = 0;
		else
			data->pause = 1;
	}
	return (0);
}
