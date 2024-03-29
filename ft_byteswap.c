/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_byteswap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 16:39:05 by dgallagh          #+#    #+#             */
/*   Updated: 2019/03/09 16:39:10 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_byteswap(char *a, char *b)
{
	if (*a != *b)
	{
		*a ^= *b;
		*b ^= *a;
		*a ^= *b;
	}
}
