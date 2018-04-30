/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adauchy <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 07:53:55 by adauchy           #+#    #+#             */
/*   Updated: 2018/01/21 01:38:47 by adauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void		ft_putnbr(int n)
{
	int	div;

	div = 1;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	while (n / div >= 10)
		div *= 10;
	while (div != 0)
	{
		ft_putchar(n / div % 10 + '0');
		div /= 10;
	}
}