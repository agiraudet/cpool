/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 07:36:35 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/27 10:29:55 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_atoi.h"
#include "ft_op.h"
#include "ft_proc_op.h"
#include "ft_print.h"

int	main(int argc, char **argv)
{
	int		(*f[5]) (int a, int b);
	int		a;
	int		b;
	char	op;

	ft_fill_op(f);
	if (argc != 4)
		return (1);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	op = ft_check_op(argv[2]);
	if (!ft_check_float_exc(op, b))
		return (1);
	ft_putnbr(ft_do_op((f), op, a, b));
	ft_putchar('\n');
}
