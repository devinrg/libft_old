/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shuffle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:16:00 by dgallagh          #+#    #+#             */
/*   Updated: 2019/02/27 17:49:25 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define ABS(x) ((x > 0) ? x : x * -1)

void	ft_shuffle(char *str, int seed)
{
	int i;
	int temp;

	i = 0;
	while (str[i])
	{
		i++;
	}
	while (--i > 0)
	{
		temp = ft_rand(seed);
		temp = ABS(temp) % (i + 1);
		ft_byteswap(&str[i], &str[temp % (i + 1)]);
	}
	while (i <= 52)
		i++;
}
