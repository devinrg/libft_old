/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 19:42:54 by dgallagh          #+#    #+#             */
/*   Updated: 2018/12/17 08:43:35 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define CAST(x) ((unsigned char*)x)[i]

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	int		x;

	i = 0;
	while (i < n)
	{
		x = CAST(s1) - CAST(s2);
		if (x != 0)
			return (x);
		i++;
	}
	return (0);
}
