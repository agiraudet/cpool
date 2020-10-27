/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:04:28 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/15 09:13:17 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_nb(int nb)
{
	char nb_a_char;
	char nb_b_char;

	if (nb <= 9)
	{
		nb_a_char = '0';
		nb_b_char = nb + 48;
	}
	else
	{
		nb_a_char = (nb / 10) + 48;
		nb_b_char = (nb % 10) + 48;
	}
	write(1, &nb_a_char, 1);
	write(1, &nb_b_char, 1);
}

void	ft_put_both_nb(int nb1, int nb2)
{
	char space_char;
	char comma_char;

	space_char = 32;
	comma_char = 44;
	ft_put_nb(nb1);
	write(1, &space_char, 1);
	ft_put_nb(nb2);
	if (!(nb1 == 98 && nb2 == 99))
	{
		write(1, &comma_char, 1);
		write(1, &space_char, 1);
	}
}

void	ft_print_comb2(void)
{
	int nb1;
	int nb2;

	nb1 = 0;
	nb2 = 1;
	while (nb1 < 99)
	{
		while (nb2 < 99)
		{
			ft_put_both_nb(nb1, nb2);
			nb2++;
		}
		ft_put_both_nb(nb1, nb2);
		nb1++;
		nb2 = nb1 + 1;
	}
}
