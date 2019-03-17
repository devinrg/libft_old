/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rand_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 15:25:19 by dgallagh          #+#    #+#             */
/*   Updated: 2019/03/09 15:25:23 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	storestr(char **dst, char *src)
{
	if (dst && *dst)
		ft_memdel((void**)(dst));
	*dst = src;
}

int				get_rand_line(int fd, char **line, int seed)
{
	char	*temp;
	int		count;
	int		ret;

	if (fd < 0 || !line)
		return (0);
	ft_rand(seed);
	temp = NULL;
	count = 1;
	while (((ret = get_next_line(fd, &temp))))
	{
		if (!(ft_rand(0) % count++))
			storestr(line, temp);
		if (*line != temp)
			ft_memdel((void**)(&temp));
	}
	if (ret == -1)
	{
		ft_memdel((void**)(&temp));
		ft_memdel((void**)(line));
		return (0);
	}
	return (1);
}
