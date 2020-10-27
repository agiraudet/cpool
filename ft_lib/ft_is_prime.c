/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:26:04 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/20 16:32:41 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int n)
{
	int		i;
	double	x;

	i = 0;
	x = (n + 1) / 2;
	while (i < 50)
	{
		x = (x + n / x) / 2;
		i++;
	}
	return ((int)x);
}

int	ft_is_prime(int nb)
{
	int x;
	int sqrt;

	sqrt = ft_sqrt(nb);
	x = 3;
	if (nb <= 1)
	{
		return (0);
	}
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
	{
		return (0);
	}
	while (x <= sqrt)
	{
		if (nb % x == 0)
			return (0);
		x += 2;
	}
	return (1);
}
