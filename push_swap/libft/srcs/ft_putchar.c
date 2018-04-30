/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 07:53:39 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/21 01:38:31 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void				ft_putchar(char c)
{
	write(1, (int*)&c, 1);
}
