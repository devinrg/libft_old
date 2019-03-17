/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 00:25:27 by dgallagh          #+#    #+#             */
/*   Updated: 2018/12/20 13:19:06 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int					word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s[i] != c && s[i] != '\0')
		count++;
	i++;
	while (s[i] != '\0')
	{
		if (s[i - 1] == c && s[i] != c)
			count++;
		i++;
	}
	return (count);
}

static	char	const		*find_not_delim(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	while (s[i] == c)
		i++;
	return (&s[i]);
}

static	size_t				strlen_delim(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char						**ft_strsplit(char const *s, char c)
{
	char	const	*ptr;
	char			**array;
	int				i;
	int				count;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] == c)
		i++;
	ptr = &s[i];
	i = 0;
	count = word_count(s, c);
	array = (char**)malloc(sizeof(char*) * (count + 1));
	if (!array)
		return (NULL);
	while (i < count)
	{
		array[i] = ft_strsub(ptr, 0, strlen_delim(ptr, c));
		ptr = find_not_delim(ptr, c);
		i++;
	}
	array[i] = NULL;
	return (array);
}
