/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 07:08:04 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/25 11:15:43 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include "ft_parse.h"

void	ft_check_dir(int dir, int i, int *x, int *y)
{
	if (dir == 0)
		*x = i;
	else if (dir == 1)
		*x = SIZE - 1 - i;
	else if (dir == 2)
		*y = i;
	else if (dir == 3)
		*y = SIZE - 1 - i;
}

int		ft_check_view(int **map, int dir, int start)
{
	int i;
	int x;
	int y;
	int view;
	int tallest;

	i = 0;
	x = start;
	y = start;
	view = 0;
	tallest = 0;
	while (i < SIZE)
	{
		ft_check_dir(dir, i, &x, &y);
		if (map[x][y] > tallest)
		{
			tallest = map[x][y];
			view++;
		}
		i++;
	}
	return (view);
}

int		ft_check_col(int **map, t_rules rule)
{
	int i;

	i = 0;
	while (i < SIZE)
	{
		if (ft_check_view(map, 0, i) != rule.colup[i])
			return (0);
		if (ft_check_view(map, 1, i) != rule.coldown[i])
			return (0);
		i++;
	}
	return (1);
}

int		ft_check_double(int **map, int value, t_point point)
{
	int xi;
	int yi;

	xi = 0;
	yi = 0;
	while (xi < point.x)
	{
		if (value == map[xi][point.y])
			return (0);
		xi++;
	}
	while (yi < point.y)
	{
		if (value == map[point.x][yi])
			return (0);
		yi++;
	}
	return (1);
}

int		ft_check_argv(char *arg)
{
	int i;
	int arglen;

	arglen = 0;
	while (arg[arglen])
		arglen++;
	if (arglen != (SIZE * 4 * 2 - 1))
		return (0);
	i = 0;
	while (arg[i])
	{
		if (!ft_is_num(arg[i]) || arg[i] <= '0' || arg[i] - 48 > SIZE)
			return (0);
		i++;
		if (arg[i])
			if (arg[i++] != ' ')
				return (0);
	}
	return (1);
}
