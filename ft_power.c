/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 20:31:28 by dgallagh          #+#    #+#             */
/*   Updated: 2019/02/21 20:58:31 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_power(int base, int power)
{
	if (power == 0)
		return (1);
	while (power > 0)
	{
		base = base * base;
		power--;
	}
	return (base);
}
