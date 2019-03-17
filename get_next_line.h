/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 18:56:49 by dgallagh          #+#    #+#             */
/*   Updated: 2019/02/22 16:17:49 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 4

# include "libft.h"

typedef	struct			s_fd_list
{
	int					fildes;
	char				buffer[BUFF_SIZE];
	int					eof;
	ssize_t				size;
	struct s_fd_list	*next;
}						t_fd_list;

int						get_next_line(const int fd, char **line);

#endif
