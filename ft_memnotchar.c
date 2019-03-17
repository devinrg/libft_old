/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memnotchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 02:16:31 by dgallagh          #+#    #+#             */
/*   Updated: 2019/01/10 02:29:29 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memnotchar(const void *s, char c, size_t n)
{
	size_t	i;

	i = 0;
	while (*(char*)(s + i) == c && i < n)
	{
		i++;
	}
	if (i < n)
		return ((void*)(s + i));
	return (NULL);
}
