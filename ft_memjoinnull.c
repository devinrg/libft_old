/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoinnull.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:53:34 by dgallagh          #+#    #+#             */
/*   Updated: 2019/02/20 14:53:38 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	norm(ssize_t *i, ssize_t *j)
{
	*i = -1;
	*j = -1;
}

void		*ft_memjoinnull(void *ptr1, ssize_t s1, void *ptr2, ssize_t s2)
{
	void	*ret;
	ssize_t	i;
	ssize_t	j;

	norm(&i, &j);
	if (!ptr1)
		s1 = 0;
	if (!ptr2)
		s2 = 0;
	if (!s1 && !s2)
	{
		ret = malloc(1);
		((char*)ret)[0] = '\0';
		return (ret);
	}
	ret = malloc(s1 + s2 + 1);
	if (!ret)
		return (NULL);
	while (++i < s1)
		((char*)ret)[i] = ((char*)ptr1)[i];
	while (++j < s2)
		((char*)ret)[i + j] = ((char*)ptr2)[j];
	((char*)ret)[i + j] = '\0';
	return (ret);
}
