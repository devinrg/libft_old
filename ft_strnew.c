/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 23:19:24 by dgallagh          #+#    #+#             */
/*   Updated: 2018/12/17 14:48:26 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	ft_bzero(str, size + 1);
	return (str);
}
