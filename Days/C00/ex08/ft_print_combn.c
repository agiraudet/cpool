/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 09:22:59 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/15 10:16:26 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_check_last_number(int n, int *tab)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (tab[i] != 10 - (n - i))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_print_array(int n, int *tab)
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = tab[i] + 48;
		write(1, &c, 1);
		i++;
	}
	if (!ft_check_last_number(n, tab))
	{
		c = ',';
		write(1, &c, 1);
		c = ' ';
		write(1, &c, 1);
	}
}

int		determine_index(int *tab, int n)
{
	int i;

	i = n - 1;
	while (i >= 0)
	{
		if (tab[i] >= 10 - n + i)
		{
			i--;
		}
		else
		{
			return (i);
		}
	}
	return (0);
}

void	reset_bigger_char(int index, int n, int *tab)
{
	int i;

	i = 1;
	if (index <= n - 1)
	{
		while (index + i <= n - 1)
		{
			tab[index + i] = tab[index + i - 1] + 1;
			i++;
		}
	}
}

void	ft_print_combn(int n)
{
	int tab[n];
	int index;
	int i;

	i = 0;
	while (i < n)
	{
		tab[i] = i;
		i++;
	}
	ft_print_array(n, tab);
	while (tab[0] != 10 - n)
	{
		index = determine_index(tab, n);
		tab[index]++;
		reset_bigger_char(index, n, tab);
		ft_print_array(n, tab);
	}
}
