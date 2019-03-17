/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:36:21 by dgallagh          #+#    #+#             */
/*   Updated: 2019/02/27 10:37:35 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcasecmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	if (!s1 || !s2)
	{
		if (!s1 && s2)
			return ((int)s2[0]);
		if (!s2 && s1)
			return ((int)s1[0]);
		return (-1);
	}
	while (ft_toupper(s1[i]) == ft_toupper(s2[i]) && s1[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
