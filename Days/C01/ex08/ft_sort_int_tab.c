/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:06:56 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/19 19:45:55 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_tab_is_sorted(int *tab, int size)
{
	int i;

	if (size <= 1)
	{
		return (1);
	}
	i = 1;
	while (i < size)
	{
		if (tab[i] < tab[i - 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		ft_get_biggest_value(int *tab, int size)
{
	int biggest_value;
	int i;

	biggest_value = 0;
	i = 0;
	while (i < size)
	{
		biggest_value = (tab[i] > tab[biggest_value]) ? i : biggest_value;
		i++;
	}
	return (biggest_value);
}

void	ft_swap_value(int *tab, int elem_a, int elem_b)
{
	int c;

	c = tab[elem_a];
	tab[elem_a] = tab[elem_b];
	tab[elem_b] = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int biggest_value;

	while (size > 1)
	{
		biggest_value = ft_get_biggest_value(tab, size);
		if (biggest_value != size - 1)
		{
			ft_swap_value(tab, biggest_value, size - 1);
		}
		size--;
	}
}
