/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 19:08:10 by dgallagh          #+#    #+#             */
/*   Updated: 2018/12/14 18:21:09 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memrcpy(void *dst, const void *src, size_t len)
{
	int i;

	i = len;
	while (i > 0)
	{
		((char*)dst)[i - 1] = ((char*)src)[i - 1];
		i--;
	}
	return (dst);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src < dst)
		return (ft_memrcpy(dst, src, len));
	if (src > dst)
		return (ft_memcpy(dst, src, len));
	return (dst);
}
