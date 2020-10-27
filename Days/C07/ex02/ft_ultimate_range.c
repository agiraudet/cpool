/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 07:10:55 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/22 10:13:06 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;

	if (min >= max)
	{
		range = 0;
		return (0);
	}
	if (!((*range) = (int *)malloc((max - min) * sizeof(int))))
		return (-1);
	i = min;
	while (min < max)
	{
		(*range)[min - i] = min;
		min++;
	}
	return (min - i);
}
