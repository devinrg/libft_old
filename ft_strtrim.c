/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 21:22:17 by dgallagh          #+#    #+#             */
/*   Updated: 2018/12/20 13:19:49 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	const	char	*find_non_ws(const char *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (&s[i]);
}

static	const	char	*find_non_ws_rev(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	i--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	return (&s[i]);
}

static char				*catchblank(void)
{
	char	*ptr;

	ptr = (char*)malloc(sizeof(char) * 1);
	if (!ptr)
		return (NULL);
	*ptr = '\0';
	return (ptr);
}

char					*ft_strtrim(char const *s)
{
	char			*str;
	char	const	*start;
	char	const	*stop;
	int				i;

	if (s == NULL)
		return (NULL);
	i = 0;
	start = find_non_ws(s);
	if (start[0] == '\0')
		return (catchblank());
	stop = find_non_ws_rev(start);
	str = (char*)malloc(sizeof(char) * (stop - start + 2));
	if (!str)
		return (NULL);
	while (&start[i] != stop)
	{
		str[i] = start[i];
		i++;
	}
	str[i] = stop[0];
	str[i + 1] = '\0';
	return (str);
}
