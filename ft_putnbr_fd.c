/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 20:07:33 by dgallagh          #+#    #+#             */
/*   Updated: 2018/12/20 10:59:02 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

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

void			ft_putnbr_fd(int n, int fd)
{
	int i;
	int pwr;
	int digitz;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	i = 0;
	pwr = power(n);
	digitz = digits(n);
	if (n < 0)
		ft_putchar_fd('-', fd);
	n = absolute(n);
	while (i < digitz)
	{
		ft_putchar_fd(absolute(n / pwr) + '0', fd);
		n = n % pwr;
		pwr = pwr / 10;
		i++;
	}
}
