/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 21:12:57 by dgallagh          #+#    #+#             */
/*   Updated: 2018/12/17 18:11:01 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	minimum(size_t x, size_t y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	j;
	size_t	len;

	len = ft_strlen(dst);
	j = 0;
	if ((len + 1) < dstsize)
	{
		while (src[j] && j < (dstsize - len - 1))
		{
			dst[len + j] = src[j];
			j++;
		}
		dst[len + j] = '\0';
	}
	return ((minimum(len, dstsize)) + ft_strlen(src));
}
