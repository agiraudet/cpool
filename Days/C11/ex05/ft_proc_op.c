/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 09:16:14 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/27 11:52:35 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_op.h"
#include "ft_print.h"

int		ft_do_op(int (*f[])(int a, int b), char op, int a, int b)
{
	if (op == '+')
		return ((*f[0])(a, b));
	if (op == '-')
		return ((*f[1])(a, b));
	if (op == '*')
		return ((*f[2])(a, b));
	if (op == '/')
		return ((*f[3])(a, b));
	if (op == '%')
		return ((*f[4])(a, b));
	return (0);
}

void	ft_fill_op(int (*f[])(int a, int b))
{
	(f[0]) = &ft_add;
	(f[1]) = &ft_sub;
	(f[2]) = &ft_mul;
	(f[3]) = &ft_div;
	(f[4]) = &ft_mod;
}

char	ft_check_op(char *strop)
{
	if (strop[1])
		return (0);
	return (strop[0]);
}

int		ft_check_float_exc(char op, int b)
{
	if (op == '/' && b == 0)
	{
		ft_putstr("Stop : division by zero\n");
		return (0);
	}
	if (op == '%' && b == 0)
	{
		ft_putstr("Stop : modulo by zero\n");
		return (0);
	}
	return (1);
}
