/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:02:52 by dgallagh          #+#    #+#             */
/*   Updated: 2019/03/04 17:05:30 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char **s1, char const *s2)
{
	char *temp;

	temp = ft_strjoin(*s1, s2);
	if (!temp)
		return (NULL);
	free(*s1);
	*s1 = temp;
	return (*s1);
}
