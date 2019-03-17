/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraystr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 02:18:55 by dgallagh          #+#    #+#             */
/*   Updated: 2019/01/12 03:00:44 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	ft_arraystr searches for the first instance of string str in
**	the NULL terminated array of strings array
**
**	RETURN VALUE: the address of the first character of the first
**	string in the array to match str, or NULL, if no string
**	matching str exists in the array
*/

#include "libft.h"

char	*ft_arraystr(const char **array, const char *str)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (ft_strequ(array[i], str))
		{
			return ((char*)array[i]);
		}
		i++;
	}
	return (NULL);
}
