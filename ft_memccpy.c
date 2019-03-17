/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memccpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 20:56:33 by dgallagh          #+#    #+#             */
/*   Updated: 2019/01/12 08:03:57 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	if (n < 1)
		return (NULL);
	i = 0;
	while (i < n && *(char*)(src + i) != (char)c)
	{
		*(char*)(dst + i) = *(char*)(src + i);
		i++;
	}
	if (*(char*)(src + i) == (char)c && i != n)
	{
		*(char*)(dst + i) = *(char*)(src + i);
		return (dst + i + 1);
	}
	return (NULL);
}
