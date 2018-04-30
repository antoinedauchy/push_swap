/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 09:12:00 by adauchy           #+#    #+#             */
/*   Updated: 2018/03/10 09:27:31 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			get_nb_str(char *str, char *sep)
{
	int		nb;
	int		n;

	n = 0;
	nb = 0;
	while (is_in_str(str[n], sep))
		n += 1;
	while (str[n])
	{
		while (!is_in_str(str[n], sep) && str[n])
			n += 1;
		nb += 1;
		while (is_in_str(str[n], sep))
			n += 1;
	}
	return (nb);
}
