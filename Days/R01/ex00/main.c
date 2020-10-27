/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/25 07:14:57 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/25 10:44:20 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "struct.h"
#include "ft_utils.h"
#include "ft_parse.h"
#include "ft_checks.h"
#include "ft_process.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int		main(int argc, char **argv)
{
	int		**map;
	int		solved;
	t_rules	rule;
	t_point	point;

	solved = 0;
	point.x = 0;
	point.y = 0;
	map = ft_create_map(SIZE);
	ft_init_map(map, SIZE);
	if (argc != 2 || !ft_check_argv(argv[1]))
	{
		ft_putstr("Error\n");
		return (0);
	}
	rule = ft_set_rules(argv[1]);
	ft_process(map, point, rule, &solved);
	if (!solved)
		ft_putstr("Error\n");
	return (0);
}
