/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:06:03 by dgallagh          #+#    #+#             */
/*   Updated: 2018/12/20 10:57:12 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int		absolute(int n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

static	int		digits(int n)
{
	int i;
	int pwr;

	n = absolute(n);
	i = 1;
	pwr = 1;
	while (n / pwr >= 10)
	{
		pwr = pwr * 10;
		i++;
	}
	return (i);
}

static	int		power(int n)
{
	int pwr;

	n = absolute(n);
	pwr = 1;
	while (n / pwr >= 10)
		pwr = pwr * 10;
	return (pwr);
}

void			ft_putnbr(int n)
{
	int i;
	int pwr;
	int digitz;

	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	i = 0;
	pwr = power(n);
	digitz = digits(n);
	if (n < 0)
		ft_putchar('-');
	n = absolute(n);
	while (i < digitz)
	{
		ft_putchar((n / pwr) + '0');
		n = n % pwr;
		pwr = pwr / 10;
		i++;
	}
}
