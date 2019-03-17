/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 21:58:43 by dgallagh          #+#    #+#             */
/*   Updated: 2018/12/11 23:24:31 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*ptr;
	size_t	i;

	if (needle[0] == '\0')
		return ((char*)haystack);
	i = 0;
	ptr = ft_strchr(haystack, needle[0]);
	while (ptr != NULL)
	{
		if (ft_strnequ(ptr, needle, ft_strlen(needle)))
			return ((char*)ptr);
		ptr = ft_strchr((ptr + 1), needle[0]);
	}
	return (NULL);
}
