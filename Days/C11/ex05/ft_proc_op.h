/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_op.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraude <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 09:16:53 by agiraude          #+#    #+#             */
/*   Updated: 2020/10/27 10:29:38 by agiraude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PROC_OP_H
# define FT_PROC_OP_H

int		ft_do_op(int (*f[])(int a, int b), char op, int a, int b);
void	ft_fill_op(int (*f[])(int a, int b));
char	ft_check_op(char *strop);
int		ft_check_float_exc(char op, int b);

#endif
