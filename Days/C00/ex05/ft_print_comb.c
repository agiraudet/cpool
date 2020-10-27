/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 11:54:07 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/15 20:16:53 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_array(int *tab)
{
	int		i;
	char	c;
	char	buffer[2];

	buffer[0] = ',';
	buffer[1] = ' ';
	i = 0;
	while (i < 3)
	{
		c = tab[i] + 48;
		write(1, &c, 1);
		i++;
	}
	if (!((tab[0] == 7 && tab[1] == 8) && tab[2] == 9))
	{
		write(1, buffer, 2);
	}
}

void	ft_print_comb(void)
{
	int tab[3];

	tab[0] = 0;
	tab[1] = 1;
	tab[2] = 2;
	while (tab[0] < 7)
	{
		while (tab[1] < 8)
		{
			while (tab[2] < 9)
			{
				ft_print_array(tab);
				tab[2]++;
			}
			ft_print_array(tab);
			tab[1]++;
			tab[2] = tab[1] + 1;
		}
		ft_print_array(tab);
		tab[0]++;
		tab[1] = tab[0] + 1;
		tab[2] = tab[1] + 1;
	}
	ft_print_array(tab);
}
