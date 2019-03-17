/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 17:53:34 by dgallagh          #+#    #+#             */
/*   Updated: 2019/02/25 10:03:16 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	norm(ssize_t *i, ssize_t *j)
{
	*i = -1;
	*j = -1;
}

void		*ft_memjoin(void *ptr1, ssize_t size1, void *ptr2, ssize_t size2)
{
	void	*ret;
	ssize_t	i;
	ssize_t	j;

	norm(&i, &j);
	if (!ptr1)
		size1 = 0;
	if (!ptr2)
		size2 = 0;
	if (!size1 && !size2)
	{
		ret = malloc(1);
		((char*)ret)[0] = '\0';
		return (ret);
	}
	ret = malloc(size1 + size2);
	if (!ret)
		return (NULL);
	while (++i < size1)
		((char*)ret)[i] = ((char*)ptr1)[i];
	while (++j < size2)
		((char*)ret)[i + j] = ((char*)ptr2)[j];
	return (ret);
}
