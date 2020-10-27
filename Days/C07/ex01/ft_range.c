/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 17:55:14 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/22 10:46:32 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int *tab;
	int i;

	if (min >= max)
	{
		tab = 0;
		return (tab);
	}
	tab = (int *)malloc((max - min) * sizeof(int));
	i = min;
	while (min < max)
	{
		tab[min - i] = min;
		min++;
	}
	return (tab);
}
