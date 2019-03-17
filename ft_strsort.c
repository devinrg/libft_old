/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 17:29:49 by dgallagh          #+#    #+#             */
/*   Updated: 2019/02/27 18:28:37 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	ft_insert(char *str, int j, int i)
{
	char temp;

	temp = str[j];
	str[j++] = str[i];
	while (j <= i)
	{
		ft_byteswap(&str[j], &temp);
		j++;
	}
}

int			ft_strsort(char *str)
{
	int i;
	int j;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < i)
		{
			if (str[j] > str[i])
			{
				ft_insert(str, j, i);
				break ;
			}
			j++;
		}
		i++;
	}
	return (1);
}
