/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 07:05:16 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/25 10:13:10 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	ft_putint(int i)
{
	char c;

	c = i + 48;
	write(1, &c, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_map(int **map, int size, int *solved)
{
	int x;
	int y;

	x = 0;
	*solved = 1;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			ft_putint(map[x][y++]);
			if (y != size)
				ft_putchar(' ');
		}
		ft_putchar('\n');
		x++;
	}
}

int		**ft_create_map(int size)
{
	int **map;
	int i;

	if (!(map = (int **)malloc(size * sizeof(int *))))
		return (0);
	i = 0;
	while (i < size)
		if (!(map[i++] = (int *)malloc(size * sizeof(int))))
			return (0);
	return (map);
}

void	ft_init_map(int **map, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
			map[i][j++] = 0;
		i++;
	}
}
