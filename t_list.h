/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_list.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 23:34:48 by dgallagh          #+#    #+#             */
/*   Updated: 2019/01/04 23:52:03 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_LIST_H
# define T_LIST_H

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

#endif
