/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 06:58:32 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/17 07:02:07 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	select_char(int border, char *c1, char *c2)
{
	if (border)
	{
		*c1 = 'o';
		*c2 = '-';
	}
	else
	{
		*c1 = '|';
		*c2 = ' ';
	}
}

void	draw_line(int x, int border)
{
	char	c1;
	char	c2;
	int		xi;

	select_char(border, &c1, &c2);
	xi = 0;
	while (xi < x)
	{
		if (xi == x - 1)
		{
			ft_putchar(c1);
			ft_putchar('\n');
		}
		else if (xi == 0)
		{
			ft_putchar(c1);
		}
		else
		{
			ft_putchar(c2);
		}
		xi++;
	}
}

void	rush(int x, int y)
{
	int yi;
	int xi;

	yi = 0;
	while (yi < y)
	{
		if (yi == 0 || yi == y - 1)
		{
			draw_line(x, 1);
		}
		else
		{
			draw_line(x, 0);
		}
		yi++;
	}
}
