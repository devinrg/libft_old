/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:43:32 by dgallagh          #+#    #+#             */
/*   Updated: 2018/12/20 10:30:14 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strdigit(char const *str)
{
	int i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}

static char	*skipwhite(char const *str)
{
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	return ((char*)str);
}

static int	isminus(char c)
{
	if (c == '-')
		return (-1);
	return (1);
}

static int	checklong(char const *str)
{
	int		isnegative;
	char	*strmin;
	char	*strmax;

	strmin = "-922337203685477580820";
	strmax = "9223372036854775807";
	str = skipwhite(str);
	isnegative = isminus(*str);
	if (isnegative == -1)
	{
		if (strdigit(str) > 20)
			return (0);
		if (strdigit(str) == 20 && ft_strcmp(str, strmin) > 0)
			return (0);
	}
	if (isnegative == 1)
	{
		if (strdigit(str) > 19)
			return (-1);
		if (strdigit(str) == 19 && ft_strcmp(str, strmax) > 0)
			return (-1);
	}
	return (1);
}

int			ft_atoi(const char *str)
{
	int isnegative;
	int i;
	int value;

	if (checklong(str) == -1 || checklong(str) == 0)
		return (checklong(str));
	isnegative = 1;
	i = 0;
	value = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		isnegative = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	else
		isnegative = 1;
	while (ft_isdigit(str[i]))
		value = value * 10 + (str[i++] - '0');
	return (value * isnegative);
}
