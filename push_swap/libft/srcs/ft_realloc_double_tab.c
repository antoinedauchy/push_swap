/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_double_tab.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 18:17:18 by adauchy           #+#    #+#             */
/*   Updated: 2018/03/15 20:10:15 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char			**ft_realloc_double_tab(char **tab, int size_tab, int add)
{
	char	**ret;
	int		n;

	if (!tab)
		return (NULL);
	if (!(ret = (char**)malloc((size_tab + add + 1) * sizeof(char*))))
		return (NULL);
	n = 0;
	while (tab[n])
	{
		ret[n] = tab[n];
		n += 1;
	}
	while (n <= size_tab + add)
	{
		ret[n] = NULL;
		n += 1;
	}
	free(tab);
	return (ret);
}
