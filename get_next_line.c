/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 16:13:04 by dgallagh          #+#    #+#             */
/*   Updated: 2019/02/25 19:08:24 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

static t_fd_list	*find_fildes(t_fd_list **list, int fd)
{
	t_fd_list	**ptr;

	ptr = list;
	while (*ptr && (*ptr)->fildes != fd)
		ptr = &((*ptr)->next);
	if (*ptr == NULL)
	{
		*ptr = (t_fd_list*)malloc(sizeof(t_fd_list) * 1);
		(*ptr)->fildes = fd;
		(*ptr)->eof = 0;
		(*ptr)->size = 0;
		(*ptr)->next = NULL;
	}
	if ((*ptr)->size < 0)
		(*ptr)->size = 0;
	if ((*ptr)->eof)
		(*ptr)->eof = 0;
	return (*ptr);
}

static int			buff_write(char **line, t_fd_list *ptr, ssize_t *size)
{
	char		*c;
	ssize_t		x;
	char		*temp;

	c = (char*)ft_memchr(ptr->buffer, '\n', ptr->size);
	x = (c) ? c - ptr->buffer : ptr->size;
	temp = (char*)ft_memjoinnull(*line, *size, ptr->buffer, x);
	if (*line)
		free(*line);
	*line = temp;
	*size += x;
	if (c && ptr->size > x)
		ft_memmove(ptr->buffer, c + 1, ptr->size - (x + 1));
	ptr->size = c ? ptr->size - (x + 1) : 0;
	return (c ? 1 : 0);
}

static int			buff_read(t_fd_list *ptr, char **line)
{
	if (!ptr->size)
		ptr->size = read(ptr->fildes, ptr->buffer, BUFF_SIZE);
	if (ptr->size == -1)
	{
		if (*line)
			ft_strdel(line);
		ptr->size = -1;
		return (0);
	}
	if (ptr->size == 0 && ptr->fildes)
		ptr->eof = 1;
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_fd_list	*list = NULL;
	char				x;
	t_fd_list			*ptr;
	ssize_t				size;

	if (fd < 0 || !line)
		return (-1);
	ptr = find_fildes(&list, fd);
	*line = NULL;
	size = 0;
	x = 0;
	while (1)
	{
		if (((buff_read(ptr, line) && ptr->size < 1) || ptr->size == -1))
			return ((x && ptr->size != -1) ? x : ptr->size);
		if (buff_write(line, ptr, &size) ^ ptr->eof)
			return (1);
		x = 1;
	}
}
