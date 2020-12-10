/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 07:18:34 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/27 13:33:09 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int *ret;
	int i;

	if (!(ret = (int *)malloc(length * sizeof(int))))
		return (0);
	i = 0;
	while (i < length)
	{
		ret[i] = (*f)(tab[i]);
		i++;
	}
	return (ret);
}
