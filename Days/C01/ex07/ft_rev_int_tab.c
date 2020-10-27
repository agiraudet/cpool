/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 14:02:09 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/15 18:04:36 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int rev_tab[size];
	int i;

	i = 0;
	while (i < size)
	{
		rev_tab[size - i - 1] = tab[i];
		i++;
	}
	i = 0;
	while (i < size)
	{
		tab[i] = rev_tab[i];
		i++;
	}
}
