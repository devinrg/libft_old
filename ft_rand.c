/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallagh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 16:37:33 by dgallagh          #+#    #+#             */
/*   Updated: 2019/03/09 16:37:38 by dgallagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define A 14
#define B 13
#define C 15

int	ft_rand(int seed)
{
	static int	prev_seed = 0;
	static int	num = 0b01100101100001101100001011101010;

	if (seed && seed != prev_seed)
	{
		prev_seed = seed;
		num = seed;
	}
	num ^= num << A;
	num ^= num >> B;
	num ^= num << C;
	return (num);
}
