/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_simple_tab.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 18:29:59 by adauchy           #+#    #+#             */
/*   Updated: 2018/03/10 08:19:06 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int			*ft_realloc_simple_tab(int *tab, int *size, int add)
{
	int		*ret;
	int		n;

	if (!(ret = (int*)malloc((*size + add) * sizeof(int))))
		return (NULL);
	n = 0;
	while (n < *size)
	{
		ret[n] = tab[n];
		n += 1;
	}
	if (tab)
		free(tab);
	*size += add;
	return (ret);
}
