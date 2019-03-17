/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 22:36:57 by dgallagh          #+#    #+#             */
/*   Updated: 2018/12/11 22:23:31 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list				*link;
	static	int			allocation_good = 1;

	link = (*f)(lst);
	if (link == NULL)
		allocation_good = 0;
	if (allocation_good == 1)
	{
		if (lst->next != NULL)
		{
			link->next = ft_lstmap(lst->next, (*f));
		}
		else
			link->next = NULL;
	}
	if (allocation_good == 0)
		return (NULL);
	return (link);
}
