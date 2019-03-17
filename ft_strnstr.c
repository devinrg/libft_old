/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 17:02:58 by dgallagh          #+#    #+#             */
/*   Updated: 2018/12/12 02:06:08 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#define MIN(x, y) (x < y) ? x : y
#define REMAIN len - (ptr - haystack)
#define BODY const char *haystack, const char *needle, size_t len

static char	*ft_strnchr(const char *str, const char c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && str[i] != c && str[i] != '\0')
		i++;
	if (str[i] == c)
		return ((char*)(&(str[i])));
	else
		return (NULL);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*ptr;
	int		x;
	size_t	needlelen;

	if (needle[0] == '\0')
		return ((char*)haystack);
	needlelen = ft_strlen(needle);
	ptr = ft_strnchr(haystack, needle[0], len);
	while (ptr != NULL)
	{
		if (REMAIN >= needlelen)
		{
			x = ft_strncmp(ptr, needle, MIN(needlelen, REMAIN));
		}
		else
			return (NULL);
		if (x == 0)
		{
			return (ptr);
		}
		ptr = ft_strnchr(ptr + 1, needle[0], REMAIN);
	}
	return (NULL);
}
