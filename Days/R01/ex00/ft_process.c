/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 08:04:14 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/25 11:15:20 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "ft_checks.h"
#include "ft_utils.h"

int		ft_check_entry(int **map, int x, t_rules rule)
{
	if (ft_check_view(map, 2, x) == rule.rowleft[x])
		if (ft_check_view(map, 3, x) == rule.rowright[x])
			return (1);
	return (0);
}

int		ft_init(int *x, int *y)
{
	*x = *x + 1;
	*y = 0;
	return (1);
}

void	ft_stock_n_increment(int **map, int height, int x, int *y)
{
	map[x][*y] = height;
	*y = *y + 1;
}

void	ft_backtrack(int **map, int x, int *y)
{
	*y -= 1;
	map[x][*y] = 0;
}

int		ft_process(int **map, t_point point, t_rules rule, int *solved)
{
	int height;

	height = 1;
	if (point.x >= SIZE)
		return (1);
	if (point.y >= SIZE)
	{
		if (ft_check_entry(map, point.x, rule) && ft_init(&point.x, &point.y))
			if (ft_process(map, point, rule, solved))
				if (ft_check_col(map, rule) && !*solved)
					ft_print_map(map, SIZE, solved);
	}
	else
		while (height <= SIZE)
		{
			if (ft_check_double(map, height, point))
			{
				ft_stock_n_increment(map, height, point.x, &point.y);
				ft_process(map, point, rule, solved);
				ft_backtrack(map, point.x, &point.y);
			}
			height++;
		}
	return (0);
}
