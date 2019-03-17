/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:43:33 by dgallagh          #+#    #+#             */
/*   Updated: 2018/12/17 15:13:59 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	absolute(int n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

static int	power(int n)
{
	int pwr;

	n = absolute(n);
	pwr = 1;
	while (n / pwr >= 10)
		pwr = pwr * 10;
	return (pwr);
}

static int	digits(int n)
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

static char	*if_int_min(void)
{
	char *ptr;

	ptr = (char*)malloc(sizeof(char) * 11);
	if (!ptr)
		return (NULL);
	ptr[0] = '-';
	ptr[1] = '2';
	ptr[2] = '1';
	ptr[3] = '4';
	ptr[4] = '7';
	ptr[5] = '4';
	ptr[6] = '8';
	ptr[7] = '3';
	ptr[8] = '6';
	ptr[9] = '4';
	ptr[10] = '8';
	return (ptr);
}

char		*ft_itoa(int n)
{
	int		pwr;
	int		i;
	int		j;
	char	*ptr;

	if (n == INTMIN)
		return (if_int_min());
	pwr = power(n);
	i = digits(n);
	j = 0;
	if (n < 0)
		i++;
	ptr = (char*)malloc(sizeof(char) * (i + 1));
	if (ptr == NULL)
		return (ptr);
	if (n < 0)
		ptr[j++] = '-';
	while (j < i)
	{
		ptr[j++] = absolute(n / pwr) + '0';
		n = n % pwr;
		pwr = pwr / 10;
	}
	ptr[j] = '\0';
	return (ptr);
}
