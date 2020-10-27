/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 16:25:35 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/20 16:25:40 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_board(int *board)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
	c = '\n';
	write(1, &c, 1);
}

int		is_safe(int *board, int x, int y)
{
	int xi;

	xi = 0;
	while (xi < x)
	{
		if (board[xi] == y)
			return (0);
		xi++;
	}
	xi = 0;
	while (xi < x)
	{
		if (board[xi] == y - (x - xi))
			return (0);
		xi++;
	}
	xi = 0;
	while (xi < x)
	{
		if (y + (x - xi) < 10)
			if (board[xi] == y + (x - xi))
				return (0);
		xi++;
	}
	return (1);
}

int		recur(int *board, int x, int *total)
{
	int yi;

	if (x >= 10)
	{
		return (1);
	}
	yi = 0;
	while (yi < 10)
	{
		if (is_safe(board, x, yi))
		{
			board[x] = yi;
			if (recur(board, x + 1, total))
			{
				ft_print_board(board);
				*total += 1;
			}
			board[x] = -1;
		}
		yi++;
	}
	return (0);
}

int		ft_ten_queens_puzzle(void)
{
	int board[10];
	int total;
	int i;

	total = 0;
	i = 0;
	while (i < 10)
		board[i++] = -1;
	recur(board, 0, &total);
	return (total);
}
